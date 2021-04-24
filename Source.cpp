#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <fstream>
#include <random>
#include <cassert>
#include <cmath>
#include <math.h>
#include <assert.h>
#include <unordered_map>
#include <functional>
#define zero 0.
#define one 1.

using namespace std;

inline double z_stat(const double& u, const double& n, const double& m) {
	double Z = (u - 0.5 * m * n) / sqrt((m * n * (m + n + 1.) / 12.));
	return Z;
}

double inv_normalDF(const double& level) // error ~ O(10^-5)
{
	double q, t;
	assert((level > zero) && (level < one));
	t = level < 0.5 ? level : one - level;
	t = sqrt(-2 * log(t));
	q = t - ((0.010328 * t + 0.802853) * t + 2.515517) /
		(((0.001308 * t + 0.189269) * t + 1.432788) * t + 1);
	return level > 0.5 ? q : -q;
}

std::pair<double, double> getRank(const std::vector<std::pair<double, int> >& a) {
    std::vector<double> _rank(a.size());
    double rankX = 0., rankY = 0.;
    double _count = 1.;
    for (size_t i = 0; i < a.size(); ++i) {
        _rank[i] = _count;
        ++_count;
    }
    double avg;
    bool inSeq = false;
    double startVal = HUGE_VAL;
    size_t startIndex = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (inSeq) {
            if (a[i].first == startVal) continue;
            avg = (_rank[startIndex] + _rank[i - 1]) / 2.0;
            for (size_t j = startIndex; j < i; ++j) _rank[j] = avg;
            startIndex = i;
            startVal = a[i].first;
            inSeq = false;
        }
        else {
            if (a[i].first == startVal) {
                startIndex = i - 1;
                inSeq = true;
            }
            else startVal = a[i].first;
        }
    }
    if (inSeq) {
        size_t lastIndex = _rank.size() - 1;
        avg = (_rank[startIndex] + _rank[lastIndex]) / 2.0;
        for (size_t j = startIndex; j <= lastIndex; ++j) _rank[j] = avg;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].second == 1) rankX += _rank[i];
        else if (a[i].second == 2) rankY += _rank[i];
    }
    return std::make_pair(rankX, rankY);
}
int main() {
	std::size_t n, m;
	ifstream in_x("inputX.txt"s), in_y("inputY.txt"s);
	double prob_level;
    std::cout << "Enter the probability level: "s;
	std::cin >> prob_level;
	std::cout << "H0: 2 nezavisimie viborki polucheni iz odnoy general`noy sovokupnosti, ne otlichayutsta po nablyudaemonu priznaku."s << std::endl;
	std::vector<std::pair<double, int> >x;
    double text_in, y_in;
    while (in_x >> text_in) {
        x.push_back({ text_in, 1 });     
    }
    n = x.size();
    while (in_y >> y_in) {
        x.push_back({ y_in, 2 });
    }
    m = x.size() - n;
	std::sort(x.begin(), x.end());
    std::pair<double, int> res = getRank(x);
	double Rx = res.first, Ry = res.second, count = 1, coun = 0;
	double Ux = (double)m * (double)n + 0.5 * (double)m * ((double)m + 1.) - (double)Rx;
	double Uy = (double)m * (double)n + 0.5 * (double)n * ((double)n + 1.) - (double)Ry;
	double U = std::min(Ux, Uy);
    std::pair<double, double> OFFSET_U = {inv_normalDF(0.5 * prob_level), inv_normalDF(1 - 0.5 * prob_level)};
	if (n > 8 && m > 8) {
        std::cout << "Using Z-STAT..."s << std::endl;
		if (abs(z_stat(U, n, m)) <= inv_normalDF(1 - (prob_level * 0.5))) cout << "Accepted."s << endl;
		else std::cout << "H0 not accepted."s << std::endl;
	}
    else if (U < OFFSET_U.first || U > OFFSET_U.second) {
        std::cout << "H0 not accepted"s << std::endl;
    }
    else std::cout << "Accepted."s << std::endl;
	return 0;
}