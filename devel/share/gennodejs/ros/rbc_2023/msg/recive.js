// Auto-generated. Do not edit!

// (in-package rbc_2023.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class recive {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.LaunchSpeed = null;
    }
    else {
      if (initObj.hasOwnProperty('LaunchSpeed')) {
        this.LaunchSpeed = initObj.LaunchSpeed
      }
      else {
        this.LaunchSpeed = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type recive
    // Serialize message field [LaunchSpeed]
    bufferOffset = _serializer.float64(obj.LaunchSpeed, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type recive
    let len;
    let data = new recive(null);
    // Deserialize message field [LaunchSpeed]
    data.LaunchSpeed = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rbc_2023/recive';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ad511b29776a364dc3562d699cb5c9b0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 LaunchSpeed
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new recive(null);
    if (msg.LaunchSpeed !== undefined) {
      resolved.LaunchSpeed = msg.LaunchSpeed;
    }
    else {
      resolved.LaunchSpeed = 0.0
    }

    return resolved;
    }
};

module.exports = recive;
