# IoT Device Communication System with QEMU

## Project Overview

- This project implements an IoT device communication system that facilitates the transmission of sensor data between multiple QEMU client devices and a central server running on UBUNTU. 
- The communication occurs through TCP and UDP sockets, and the system is implemented in C++ using object-oriented principles. 
- The project consists of both unicast and multicast server-client applications, with all socket communication abstracted into well-structured, object-oriented classes.

The goal is to demonstrate practical knowledge of:
- Socket programming (TCP/UDP)
- Yocto for building OS
- Makefile for automating the build process
- Real-time data transmission in an IoT context

## Project Structure

The project is divided into two main parts:

### 1. Unicast TCP Server/Client Application
- **Server**: UBUNTU
- **Client**: QEMU (Emulated Environment)

### 2. Multicast UDP Server/Client Application
- **Server**: QEMU
- **Client 1**: UBUNTU
- **Client 2**: UBUNTU

The communication system uses TCP for unicast communication and UDP for multicast, both implemented with C++ classes that encapsulate the socket communication logic.

## Project files

- Full source code implementing the project.
- Yocto recipes for building the project.
- Project documentation, including:
  - Class structure and design decisions
  - Step-by-step guide for setting up the development environment (QEMU) with Yocto
  - Usage instructions (commands to run the server and clients)

## Getting Started

Follow the uploaded PDF steps to set up the development environment and run the project.
