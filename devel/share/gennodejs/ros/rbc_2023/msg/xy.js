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

class xy {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.V = null;
    }
    else {
      if (initObj.hasOwnProperty('V')) {
        this.V = initObj.V
      }
      else {
        this.V = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type xy
    // Serialize message field [V]
    bufferOffset = _serializer.string(obj.V, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type xy
    let len;
    let data = new xy(null);
    // Deserialize message field [V]
    data.V = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.V);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rbc_2023/xy';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '18370905db842ff9f15c0610f2c0d8e2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string V
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new xy(null);
    if (msg.V !== undefined) {
      resolved.V = msg.V;
    }
    else {
      resolved.V = ''
    }

    return resolved;
    }
};

module.exports = xy;
