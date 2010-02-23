/*********************************************************************
 * Copyright (c) 2009, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Author: Kevin Watts
 */

#ifndef MOTOR_JOINT_CALIBRATION_CONTROLLER_H
#define MOTOR_JOINT_CALIBRATION_CONTROLLER_H


#include "ros/node_handle.h"
#include "pr2_mechanism_model/robot.h"
#include "realtime_tools/realtime_publisher.h"
#include "std_msgs/Empty.h"
#include <boost/scoped_ptr.hpp>
#include "pr2_controller_interface/controller.h"

namespace controller
{

class MotorJointCalibrationController : public pr2_controller_interface::Controller
{

public:
  MotorJointCalibrationController();
  virtual ~MotorJointCalibrationController();

  virtual bool init(pr2_mechanism_model::RobotState *robot, ros::NodeHandle &n);

  virtual void update();


protected:

  pr2_mechanism_model::RobotState* robot_;
  ros::NodeHandle node_;
  boost::scoped_ptr<realtime_tools::RealtimePublisher<std_msgs::Empty> > pub_calibrated_;
  ros::Time last_publish_time_;

  pr2_mechanism_model::JointState *joint_;


};

}


 #endif // MOTOR_JOINT_CALIBRATION_CONTROLLER_H
