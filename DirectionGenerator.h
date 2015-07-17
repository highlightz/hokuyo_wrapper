#ifndef DIRECTIONGENERATOR_H
#define DIRECTIONGENERATOR_H

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setprecision;
using std::fixed;

#include <vector>
using std::vector;

#define SQUARE(A) (((A) * (A)))

class DirectionGenerator
{
public:
    DirectionGenerator( ) : artificial_force_seq( 721 ) {}
    // Set interest radius, the unit is mm
    void setInterestRadius( long radius );
    double process( vector< long > distance );
private:
    long interestRadius;

    // Mapping: [-90 deg, +90 deg] -> [-360, +360] -> [0, 720]
    int deg2step( double deg );

    int step2index( int step );

    double index2rad( int index );

    double deg2rad( double deg );

    // Algorithm 1
    struct artificial_force
    {
        double f_x;
        double f_y;
        artificial_force( )
        {
            f_x = 0;
            f_y = 0;
        }
    };
    vector< artificial_force > artificial_force_seq;
    double sumArtificialForces( vector< long > distance );

    // Algorithm 2
    int findIndexOfMaxValue( long sum[], int length );
    double selectFromFixedDirections( vector< long > distance );

    // Algorithm 3
    double sumFixedArtificialForces( vector< long > distance );

    // Algorithm 4
    void segAverage( long& sum, vector< long > distance, int start_indx, int end_indx );
    double slideWindow( vector< long > distance );

    // Algorithm 5
    // Find the direction with the longest distance,
    // meanwhile, check its neighbors' distances
};

#endif // DIRECTIONGENERATOR_H

