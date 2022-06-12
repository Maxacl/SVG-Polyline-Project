

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void beginHtmlSVG ( int wide, int high, char* backColor)
{
    printf ( "<!DOCTYPE html>\n" ) ;
    printf ( "<html>\n" ) ;
    printf ( "<body>\n" ) ;

    printf( "<svg height='%d' width='%d' style='stroke-width: 0px; background-color: %s;'>\n",
        high, wide, backColor ) ;
}

void endHtmlSVG ( )
{
    printf( "</svg>\n") ;
    printf ( "</body>\n" ) ;
    printf ( "</html>\n" ) ;
}

char* getRGBColor ( int red, int green, int blue )
{
    static char* svgFillString = "rgb(%d, %d, %d)" ;
    static char result[100] = { 0 } ;
    sprintf( result, svgFillString, red, green, blue ) ;
    return result ;
}


// This is my "ourPolyline" user-defined function
// This function draws a user-created polyline shape created within HTML
// Based on: https://www.w3schools.com/graphics/svg_polyline.asp
// height: How high to make the shape
// width: How wide to make the shape
// x: upper left and upper right corner of the feature horizontal
// y: upper left and upper right corner of the feature vertical
//
void ourPolyline(int height, int width, int x, int y){

    char* ourPoly = "<svg height='%d' width='%d'> "
    "x=%d y=%d"
    "<polyline points='10,25 40,25 40,55 70,55 70,25 100,25 100,55 130,55 130,25 160,25 160,55 190,55 190,25 220,25 ' "
    "style='fill:none;stroke:green;stroke-width:4' /> "
    "</svg>" ;

    printf(ourPoly, height, width, x, y);

}

int main ( )
{
    srand( time ( NULL ) ) ;

    beginHtmlSVG ( 1000, 1000, getRGBColor( 128, 0, 128 ) ) ;


    int x = ( rand ( ) % 300 ) + 200 ;
    int y = ( rand ( ) % 300  ) + 100 ;
    int size = ( rand ( ) % 150 ) + 10 ;
    int red = rand( ) % 255 ;
    int blue = rand( ) % 255 ;
    int green = rand ( ) % 255 ;


    ourPolyline( 250, 250, 350, 350 );

    for (int i; i < 20; i++) {
        ourPolyline( 250, 250, i * 40, i * 90 );
    }


    endHtmlSVG ( ) ;

    return 0 ;
}
