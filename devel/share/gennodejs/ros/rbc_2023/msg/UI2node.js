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

class UI2node {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode = null;
      this.isCheckShowWrite = null;
      this.isCheckShowRead = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('isCheckShowWrite')) {
        this.isCheckShowWrite = initObj.isCheckShowWrite
      }
      else {
        this.isCheckShowWrite = false;
      }
      if (initObj.hasOwnProperty('isCheckShowRead')) {
        this.isCheckShowRead = initObj.isCheckShowRead
      }
      else {
        this.isCheckShowRead = false;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UI2node
    // Serialize message field [mode]
    bufferOffset = _serializer.int32(obj.mode, buffer, bufferOffset);
    // Serialize message field [isCheckShowWrite]
    bufferOffset = _serializer.bool(obj.isCheckShowWrite, buffer, bufferOffset);
    // Serialize message field [isCheckShowRead]
    bufferOffset = _serializer.bool(obj.isCheckShowRead, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.int32(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UI2node
    let len;
    let data = new UI2node(null);
    // Deserialize message field [mode]
    data.mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [isCheckShowWrite]
    data.isCheckShowWrite = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [isCheckShowRead]
    data.isCheckShowRead = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.data.length;
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rbc_2023/UI2node';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3929c6344e36b839b0a0e74ac70b59cf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 mode
    bool isCheckShowWrite
    bool isCheckShowRead
    int32[] data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new UI2node(null);
    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.isCheckShowWrite !== undefined) {
      resolved.isCheckShowWrite = msg.isCheckShowWrite;
    }
    else {
      resolved.isCheckShowWrite = false
    }

    if (msg.isCheckShowRead !== undefined) {
      resolved.isCheckShowRead = msg.isCheckShowRead;
    }
    else {
      resolved.isCheckShowRead = false
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    return resolved;
    }
};

module.exports = UI2node;
