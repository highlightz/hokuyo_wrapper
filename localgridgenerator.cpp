#include "localgridgenerator.h"

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

#include <math.h>

LocalGridGenerator::LocalGridGenerator( )
{
    for ( int i = 0; i < GRID_HEIGHT; i++ )
    {
        for ( int j = 0; j < GRID_WIDTH; j++ )
        {
            grid[i][j].occupancyValue = 0;
            grid[i][j].centralX = CAR_LENGTH * ( GRID_HEIGHT - 0.5 - i );
            grid[i][j].centralY = CAR_WIDTH * ( GRID_WIDTH / 2 - 0.5 - j );
        }
    }
}

void LocalGridGenerator::setInterestRadius( long radius )
{
    interestRadius = radius;
}

void LocalGridGenerator::updateGrid( vector< long > distance )
{
    for ( int i = 0; i < GRID_HEIGHT; i++ )
    {
        for ( int j = 0; j < GRID_WIDTH; j++ )
        {
            for ( int index = 0; index < distance.capacity( ); index++ )
            {
                if ( distance[index] > interestRadius )
                {
                    continue;
                }

                double laserX = distance[index] * cos( index2rad( index ) );
                double laserY = distance[index] * sin( index2rad( index ) );

                if (    grid[i][j].centralX - CAR_LENGTH / 2 < laserX
                     && grid[i][j].centralX + CAR_LENGTH / 2 > laserX
                     && grid[i][j].centralY - CAR_WIDTH / 2 < laserY
                     && grid[i][j].centralY + CAR_WIDTH / 2 > laserY
                   )
                {
                    grid[i][j].occupancyValue++;
                }
            }
        }
    }
}

void LocalGridGenerator::showGrid( )
{
    cout << endl;
    cout << "Grid Info: " << endl;
    for ( int i = 0; i < GRID_HEIGHT; i++ )
    {
        for ( int j = 0; j < GRID_WIDTH; j++ )
        {
            cout << setw( 11 );
            cout << "( "
                 << grid[i][j].centralX / 1000
                 << ", "
                 << grid[i][j].centralY / 1000
                 << ", "
                 << grid[i][j].occupancyValue
                 << " )"
                 << '\t';
        }
        cout << endl << endl << endl << endl;
    }
    cout << endl;
}

int LocalGridGenerator::deg2step( double deg )
{
    return static_cast< int >( 4 * deg );
}

int LocalGridGenerator::step2index( int step )
{
    return step + 360;
}

double LocalGridGenerator::index2rad( int index )
{
    const double pi = 3.1415926;
    return ( index * pi / 720 - pi / 2 );
}

double LocalGridGenerator::deg2rad( double deg )
{
    const double pi = 3.1415926;
    return deg * pi / 180;
}

void LocalGridGenerator::clearGrid( )
{
    for ( int i = 0; i < GRID_HEIGHT; i++ )
    {
        for ( int j = 0; j < GRID_WIDTH; j++ )
        {
            grid[i][j].occupancyValue = 0;
        }
    }
}
