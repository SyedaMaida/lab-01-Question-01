#include <stdio.h>
int main(){
    float width;
    float height;
    float perimeter, area;
    printf("Please enter the height of rectangle: ");
    scanf("%f",&height);
    printf("\nPlease enter the width of the rectangle: ");
    scanf("%f",&width);
    perimeter=((2*height)+(2*width));
    area=height*width;
    printf("The perimeter is :%.2f \nThe area is : %.2f ",perimeter,area);
    return 0;
}
