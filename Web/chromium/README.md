# Chromium

>

## overview

Chrome has a multi-process architecture and each process is heavily multi-threaded. In this document we will go over the basic threading system shared by each process. The main goal is to keep the main thread (a.k.a. “UI” thread in the browser process) and IO thread (each process' thread for handling IPC) responsive. This means offloading any blocking I/O or other expensive operations to other threads. Our approach is to use message passing as the way of communicating between threads. We discourage locking and thread-safe objects. Instead, objects live on only one (often virtual -- we'll get to that later!) thread and we pass messages between those threads for communication.

This documentation assumes familiarity with computer science threading concepts.
