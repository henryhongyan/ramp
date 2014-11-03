#include <iostream>
#include "ros/ros.h"
#include "ramp_msgs/RampTrajectory.h"
#include "ramp_msgs/Path.h"
#include "utility.h"
#include "ramp_msgs/TrajectoryRequest.h"
#include "ramp_msgs/Population.h"
#include "ramp_msgs/BezierInfo.h"

Utility u;

int main(int argc, char** argv) {
  ros::init(argc, argv, "publish_trajectory_command");
  ros::NodeHandle handle;

  ros::Publisher pub_traj = handle.advertise<ramp_msgs::RampTrajectory>("bestTrajec", 1000);
  ros::Publisher pub_pop = handle.advertise<ramp_msgs::Population>("population", 1000);
  ros::ServiceClient client_ = handle.serviceClient<ramp_msgs::TrajectoryRequest>("trajectory_generator");



  

  ramp_msgs::KnotPoint zero;
  zero.motionState.positions.push_back(0);
  zero.motionState.positions.push_back(0);
  zero.motionState.positions.push_back(-1.09956);
  zero.motionState.velocities.push_back(0.149817);
  zero.motionState.velocities.push_back(-0.294032);
  zero.motionState.velocities.push_back(0);
  zero.motionState.accelerations.push_back(0);
  zero.motionState.accelerations.push_back(0);
  zero.motionState.accelerations.push_back(0);

  // Build a Path
  ramp_msgs::KnotPoint c1;
  c1.motionState.positions.push_back(2.5); //0.951779
  c1.motionState.positions.push_back(1.); //1.09629
  c1.motionState.positions.push_back(-PI/4); //-1.094888

  ramp_msgs::KnotPoint c2;
  c2.motionState.positions.push_back(3.5); // 0.5
  c2.motionState.positions.push_back(2.); // 2
  c2.motionState.positions.push_back(0.); //pi/4


  ramp_msgs::KnotPoint c3;
  c3.motionState.positions.push_back(1.72104); //0.95
  c3.motionState.positions.push_back(0.385994); //1.09
  c3.motionState.positions.push_back(2.78997);  //-1.09


  ramp_msgs::KnotPoint c4;
  c4.motionState.positions.push_back(3.5);
  c4.motionState.positions.push_back(2.);
  c4.motionState.positions.push_back(PI);

  
  // Velocities
  c1.motionState.velocities.push_back(0.149817);  //.151426
  c1.motionState.velocities.push_back(-0.294032); //-.297903
  c1.motionState.velocities.push_back(0.); //-.118126
 
  c2.motionState.velocities.push_back(0.);
  c2.motionState.velocities.push_back(0.);
  c2.motionState.velocities.push_back(0.);

  c3.motionState.velocities.push_back(0.);
  c3.motionState.velocities.push_back(0.);
  c3.motionState.velocities.push_back(0.); 
 
  c4.motionState.velocities.push_back(0);
  c4.motionState.velocities.push_back(0);
  c4.motionState.velocities.push_back(0); 
 

  // Accelerations
  c1.motionState.accelerations.push_back(0.); //.0114877
  c1.motionState.accelerations.push_back(0.);  //-.10465
  c1.motionState.accelerations.push_back(0.); //.0746295

  c2.motionState.accelerations.push_back(0.);
  c2.motionState.accelerations.push_back(0.);
  c2.motionState.accelerations.push_back(0.);
  
  c3.motionState.accelerations.push_back(0.);
  c3.motionState.accelerations.push_back(0.);
  c3.motionState.accelerations.push_back(0.);
  
  c4.motionState.accelerations.push_back(0.);
  c4.motionState.accelerations.push_back(0.);
  c4.motionState.accelerations.push_back(0.);
  
  ramp_msgs::Path p;
  //p.points.push_back(zero);
  p.points.push_back(c1);
  p.points.push_back(c2);
  //p.points.push_back(c3);
  //p.points.push_back(c4);
  

  /***************************************************/
  /**************** Create Curves ********************/
  /***************************************************/
 
  // Make BezierInfo from Path
  ramp_msgs::BezierInfo bi;
  
  ramp_msgs::MotionState sp0;
  //sp0 = p.points.at(0).motionState;
  //sp0 = zero.motionState;
  
  /*sp0.positions.push_back(1.24696);
  sp0.positions.push_back(0.473894);
  sp0.positions.push_back(1.41282);

  sp0.velocities.push_back(0.0525695);
  sp0.velocities.push_back(0.33);
  sp0.velocities.push_back(0);

  sp0.accelerations.push_back(0);
  sp0.accelerations.push_back(0);
  sp0.accelerations.push_back(0);*/

  
  ramp_msgs::MotionState sp1;
  //sp1 = p.points.at(1).motionState;
  //sp1 = c2.motionState;

  /*sp1.positions.push_back(0.103043);
  sp1.positions.push_back(0.5775);
  sp1.positions.push_back(1.41282);

  sp1.velocities.push_back(0.0525683);
  sp1.velocities.push_back(0.33);
  sp1.velocities.push_back(0);

  sp1.accelerations.push_back(0);
  sp1.accelerations.push_back(0);
  sp1.accelerations.push_back(0);*/

  ramp_msgs::MotionState sp2;
  //sp2 = p.points.at(2).motionState;
  //sp2 = c3.motionState;

  /*sp2.positions.push_back(0.355992);
  sp2.positions.push_back(1.45985);
  sp2.positions.push_back(1.31025);

  sp2.velocities.push_back(0.0879808);
  sp2.velocities.push_back(0.33);
  sp2.velocities.push_back(0);

  sp2.accelerations.push_back(0);
  sp2.accelerations.push_back(0);
  sp2.accelerations.push_back(0);*/

  // *** Push on the Segment points ***
  bi.segmentPoints.push_back(sp0);
  bi.segmentPoints.push_back(sp1);
  bi.segmentPoints.push_back(sp2);


  // Control Points
  
  //ramp_msgs::MotionState cp0 = sp0;
  ramp_msgs::MotionState cp0;
  /*cp0.positions.push_back(0.7387);
  cp0.positions.push_back(0.201537);
  cp0.positions.push_back(0.266344);

  cp0.velocities.push_back(0.33);
  cp0.velocities.push_back(0.0900327);
  cp0.velocities.push_back(0);
  
  cp0.accelerations.push_back(0);
  cp0.accelerations.push_back(0);
  cp0.accelerations.push_back(0);*/
  
  ramp_msgs::MotionState cp1;
  //cp1 = p.points.at(1).motionState;
  /*cp1.positions.push_back(0.103043);
  cp1.positions.push_back(0.5775);
  cp1.positions.push_back(1.37666);

  cp1.velocities.push_back(0.0525683);
  cp1.velocities.push_back(0.33);
  cp1.velocities.push_back(0);

  cp1.accelerations.push_back(0);
  cp1.accelerations.push_back(0);
  cp1.accelerations.push_back(0);*/

  ramp_msgs::MotionState cp2;
  /*cp2.positions.push_back(2.07836);
  cp2.positions.push_back(0.877559);
  cp2.positions.push_back(0.668331);*/
  
  // *** Push on the Control points ***
  /*bi.controlPoints.push_back(cp0);
  bi.controlPoints.push_back(cp1);
  bi.controlPoints.push_back(cp2);*/

  ramp_msgs::MotionState ms_initVA;
  ms_initVA.velocities.push_back(0.275025);
  ms_initVA.velocities.push_back(0.0750339);
  ms_initVA.velocities.push_back(0);
  ms_initVA.accelerations.push_back(0);
  ms_initVA.accelerations.push_back(0);
  ms_initVA.accelerations.push_back(0);

  
  ramp_msgs::MotionState ms_maxVA;
  ms_maxVA.velocities.push_back(0.33);
  ms_maxVA.velocities.push_back(0.33);
  ms_maxVA.velocities.push_back(PI/3);
  ms_maxVA.accelerations.push_back(1.);
  ms_maxVA.accelerations.push_back(1.);
  ms_maxVA.accelerations.push_back(PI/3);



  ramp_msgs::MotionState ms_begin;
  ms_begin.positions.push_back(0.841323);
  ms_begin.positions.push_back(1.31916);
  ms_begin.positions.push_back(-1.08399);

  ms_begin.velocities.push_back(0.166735);
  ms_begin.velocities.push_back(-.297418);
  ms_begin.velocities.push_back(0.231612);

  ms_begin.accelerations.push_back(0.0173546);
  ms_begin.accelerations.push_back(0.325817);
  ms_begin.accelerations.push_back(2.31612);

  //bi.ms_begin = ms_begin;
  //bi.ms_initialVA = ms_initVA;
  //bi.ms_maxVA = ms_maxVA;
 

  // u
  bi.u_0 = 0.;
  bi.u_dot_0 = 0.;
  bi.lambda = 0.;

  bi.numOfPoints = 0;


  /**************************************************/
  /**************** Curve 0 Done ********************/
  /**************************************************/

  // Curve 1
  ramp_msgs::BezierInfo bi2;


  // Segment points
  ramp_msgs::MotionState sp2_0;
  sp2_0.positions.push_back(0.076759);
  sp2_0.positions.push_back(0.4125);
  sp2_0.positions.push_back(1.41282);

  sp2_0.velocities.push_back(0.0525683);
  sp2_0.velocities.push_back(0.33);
  sp2_0.velocities.push_back(0.);

  sp2_0.accelerations.push_back(0);
  sp2_0.accelerations.push_back(0);
  sp2_0.accelerations.push_back(0);


  ramp_msgs::MotionState sp2_1 = c2.motionState;
  ramp_msgs::MotionState sp2_2 = c3.motionState;

  bi2.segmentPoints.push_back(sp2_0);
  bi2.segmentPoints.push_back(sp2_1);
  bi2.segmentPoints.push_back(sp2_2);


  // Control points
  ramp_msgs::MotionState cp2_0;
  cp2_0.positions.push_back(0.355992);
  cp2_0.positions.push_back(1.45985);
  cp2_0.positions.push_back(1.31025);
  
  cp2_0.velocities.push_back(0.0879808);
  cp2_0.velocities.push_back(0.33);
  cp2_0.velocities.push_back(0.);
  
  cp2_0.accelerations.push_back(0);
  cp2_0.accelerations.push_back(0);
  cp2_0.accelerations.push_back(0);
  
  ramp_msgs::MotionState cp2_1 = sp2_1;

  ramp_msgs::MotionState cp2_2;
  cp2_2.positions.push_back(0.75);
  cp2_2.positions.push_back(1.5);
  cp2_2.positions.push_back(-1.10715);
  
  bi2.controlPoints.push_back(cp2_0);
  bi2.controlPoints.push_back(cp2_1);
  bi2.controlPoints.push_back(cp2_2);

  // u
  bi2.u_0 = 0.; 
  bi2.u_dot_0 = 0.305471;


  ramp_msgs::MotionState ms_initVA2;
  ms_initVA2.velocities.push_back(0.0879808);
  ms_initVA2.velocities.push_back(0.33);
  ms_initVA2.velocities.push_back(0);
  ms_initVA2.accelerations.push_back(0);
  ms_initVA2.accelerations.push_back(0);
  ms_initVA2.accelerations.push_back(0);

  
  ramp_msgs::MotionState ms_maxVA2;
  ms_maxVA2.velocities.push_back(0.33);
  ms_maxVA2.velocities.push_back(0.33);
  ms_maxVA2.velocities.push_back(PI/3);
  ms_maxVA2.accelerations.push_back(0.66);
  ms_maxVA2.accelerations.push_back(0.66);
  ms_maxVA2.accelerations.push_back(PI/3);

  bi2.ms_initialVA = ms_initVA2;
  bi2.ms_maxVA = ms_maxVA2;
  
  //bi.ms_begin = p.points.at(0).motionState;
  bi2.lambda = 0.5;


  /**************************************************/
  /**************** Curve 1 Done ********************/
  /**************************************************/




  std::vector<ramp_msgs::BezierInfo> curves;
  //curves.push_back(bi);
  //curves.push_back(bi2);
  
  ramp_msgs::TrajectoryRequest tr;
  tr.request.path = p;
  tr.request.type = PARTIAL_BEZIER;
  tr.request.startBezier = false;
  tr.request.print = true;
  tr.request.bezierInfo = curves;


  std::cout<<"\nPress Enter to request and send the trajectory\n";
  std::cin.get();

  // Get and publish trajectory
  if(client_.call(tr)) {
    std::cout<<"\nSending Trajectory "<<u.toString(tr.response.trajectory);
    pub_traj.publish(tr.response.trajectory);
  }
  else {
    std::cout<<"\nSome error getting trajectory\n";
  }

  std::cout<<"\n\nPress Enter to Publish population\n";
  std::cin.get();

  // Create Population to send to trajectory_visualization
  ramp_msgs::Population pop;
  pop.population.push_back(tr.response.trajectory);
  
  pub_pop.publish(pop);


  std::cout<<"\nDifference: "<<u.findAngleFromAToB(c1.motionState.positions, c2.motionState.positions);
  std::cout<<"\nDifference: "<<u.findAngleFromAToB(c2.motionState.positions, c3.motionState.positions);


  std::cout<<"\nExiting Normally\n";
  return 0;
}
