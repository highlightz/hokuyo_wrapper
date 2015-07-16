#define _DEBUG_

#include <iostream>
using std::cout;
using std::endl;

#include "hokuyo_wrapper.h"

int main( int argc, char** argv )
{
    hokuyo_wrapper laser( argc, argv );
    laser.startHokuyo( );

    cv::Mat laserPoints;

    for ( ; ; )
    {
        laser.bufferDistance( );
        vector< long > distance = laser.getDistance( );
/*
        cout << "-67.5 deg: " << distance[ laser.urg.step2index( laser.urg.deg2step( -67.5 ) ) ] << endl;
        cout << "  -45 deg: " << distance[ laser.urg.step2index( laser.urg.deg2step( -45 ) ) ] << endl;
        cout << "    0 deg: " << distance[ laser.urg.step2index( laser.urg.deg2step( 0 ) ) ] << endl;
        cout << "   45 deg: " << distance[ laser.urg.step2index( laser.urg.deg2step( 45 ) ) ] << endl;
        cout << " 67.5 deg: " << distance[ laser.urg.step2index( laser.urg.deg2step( 67.5 ) ) ] << endl;
*/

/*
        cout << laser.urg.index2deg( laser.urg.step2index( laser.urg.deg2step( -67.5 ) ) ) << endl;
        cout << laser.urg.index2rad( laser.urg.step2index( laser.urg.deg2step( -67.5 ) ) ) << endl;
*/
        cout << "--------------------------------------------" << endl;

        laser.showDistancePoints( laserPoints );
        cv::imshow( "laserpoints", laserPoints );
        cv::waitKey( 5 );
        laserPoints.setTo( cv::Scalar( 0 ) );
    }

    return 0;
}