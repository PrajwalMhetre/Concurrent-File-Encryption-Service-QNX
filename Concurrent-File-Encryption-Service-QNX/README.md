# Concurrent File Encryption Service - QNX

## Overview

A QNX Neutrino RTOS based client-server application that performs
concurrent encryption of large data blocks using multiple worker threads.

## Objectives

- QNX Message Passing
- Client-Server architecture
- 64 KB+ payload processing
- IOV data transfer
- Thread pool based concurrent processing
- Mutex synchronization
- Condition variables
- Asynchronous event notification
- Error handling and timeout management

## Architecture

Client
    |
    | QNX Message Passing
    v
Server
    |
    +-- Worker Thread 1
    +-- Worker Thread 2
    +-- Worker Thread 3
    +-- Worker Thread 4
    |
    v
Encrypted Data
    |
    | Asynchronous Event
    v
Client

## Project Structure

```text
include/    Common message definitions
client/     Client implementation
server/     Server and thread pool
common/     Encryption implementation
docs/       Documentation
demo/       Demonstration material
test/       Test information