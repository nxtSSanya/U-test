# Mann-Whitney criterion
Allows you to determine whether two samples belong to the same general combination.</br>
So, we need to get the sum of ranks of 2 combinations. Next, use this formulas to calculate the parameters, then rate U-criterion.</br>
<img src = "http://www.machinelearning.ru/mimetex/?R_x%20=%20%5Csum_%7Bi=1%7D%5Em%20r(x_i);%5C;%5C;%5C;%5C;%20U_x%20=%20mn%20+%20%5Cfrac12m(m+1)%20-%20R_x;"/></br>
<img src = "http://www.machinelearning.ru/mimetex/?R_y%20=%20%5Csum_%7Bi=1%7D%5En%20r(y_i);%5C;%5C;%5C;%5C;%20U_y%20=%20mn%20+%20%5Cfrac12n(n+1)%20-%20R_y;"/></br>
<img src = "http://www.machinelearning.ru/mimetex/?U%20=%20%5Cmin%5Cleft%5C%7BU_x,U_y%5Cright%5C%7D."/></br>
At the last, use double-sided critical area, and accept or ignore H0 hypotesis.</br>
<img src = "http://www.machinelearning.ru/wiki/images/thumb/4/42/Standard_Normal_Density_-_Double-sided_Critical_Area.png/800px-Standard_Normal_Density_-_Double-sided_Critical_Area.png"/></br>
# When sizes of combinations X and Y are bigger then 8
In this case, we can use statistics called Z-stat</br>
<img src="https://latex.codecogs.com/svg.image?z=\frac{U-\frac{1}{2}n_1n_2}{\sqrt{\frac{1}{12}n_1n_2(n_1&plus;n_2&plus;1)}}" title="z=\frac{U-\frac{1}{2}n_1n_2}{\sqrt{\frac{1}{12}n_1n_2(n_1+n_2+1)}}"/></br>
This statistics has an normal distribution where n1 and n2 are bigger then 8.</br>
# How to use my program
You need to enter only 1 string - probability level (alpha).</br>
# Output data
Program puts "Accepted" if hypotesis is accepted, else "H0 not accepted".</br>
# Examples
Input: 0.05</br>
Output: </br>
H0 is not accepted.</br>
Samples: </br>
<pre>y       x</br>
999.5   0.5</br>
1000.4  0.4</br>
1000.7  0.7</br>
1001.7  1.6</br>
1000.3  2.3</br>
1003.7  2.9</br>
1005.9  3</br>
1007.2  3.5</br>
1008    4.1</br>
1008.5  4.7</br>
1010.3  4.7</br>
1009.7  5.5</br>
1010    5.5</br>
1008.3  6</br>
1007.4  6.4</br>
1002.1  6.9</br>
1000.7  7.7</br>
999     8.5</br>
998.3   8.5</br>
998.2   8.7</br>
998.4   9.1</br>
1005.1  9.3</br>
1003.5  9.8</br>
1001.6  8.8</br>
997.4   8.7</br>
996.6   8.6</br>
1001.6  9.8</br>
1003.2  10</br>
1004.1  10.9</br>
1001.7  10.7</br>
1001.8  10.6</br>
1002.8  10.8</br>
1003.6  11.5</br>
1004.4  11.5</br>
1002.6  12.3</br>
1001.1  13</br>
1004.4  13.2</br>
1004.3  12.8</br>
1002.4  14.1</br>
1001.5  14.4</br>
1003    13.6</br>
998.3   13.3</br>
999     13.9</br>
999.2   13</br>
1001.5  12.1</br>
1001.9  13.2</br>
1000.1  13.7</br>
1000.1  13.5</br>
1000    13.9</br>
998.8   14.4</br>
</pre>
</br>
