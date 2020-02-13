#include <stdio.h>
#include <math.h>

main()
    {
     float    x[10], y[10], xin, yout, sum;
     int      n, i, j;
  


     printf("Input number of points : n\n");
     scanf("%d", &n);
     printf("Number of points = %d\n", n);
     printf("Input the abscissas \n");
     printf("The abscissas are :\n");
     for (i = 1;  i <= n; i++)
	{ scanf("%f", &x[i]);
	  printf("%8.4f ", x[i]);
	}
	printf("Input the ordinates\n");
    printf("The ordinates are :\n");
     for (i = 1;  i <= n; i++)
	{ scanf("%f", &y[i]);
	  printf("%8.4f ", y[i]);
	}
   



     printf("Input value of x for which y is required\n");
     scanf("%f", &xin);
     printf("The value of x for which y is required is ");
     printf("%5.3f\n", xin);


     yout = 0.0;
     for (i = 1;  i <= n; i++)
	{ sum = y[i];
	  for (j = 1;  j <= n; j++)
	     { if(i != j)
	       sum = sum * (xin - x[j]) / (x[i] - x[j]);
	     }
	  yout = yout + sum;
	}
     printf("Lagrange interpolation based on %d points\n",n);
     printf("At x = %5.3f, y = %8.5f\n", xin, yout);
     
     
     return 0;
    }




