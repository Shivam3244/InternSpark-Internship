# Task 3 - System Programming / File I/O

## Project: Log Rotator

This C program demonstrates:

- File creation
- File writing
- File metadata/stat
- File renaming
- Log rotation
- Error handling

## Compile

Linux/macOS:

```bash
gcc log_rotator.c -o log_rotator
```

Run:

```bash
./log_rotator
```

Windows with MinGW:

```bash
gcc log_rotator.c -o log_rotator.exe
log_rotator.exe
```

## How it works

The program creates `application.log`. Users can append messages, check the current file size, and rotate the log. Rotation renames the current file to `application.log.1` and creates a fresh `application.log`.

## Sample

```text
1. Add log
2. Show file size
3. Rotate log
4. Exit

Enter choice: 1
Enter log message: Application started
Log added successfully.

Enter choice: 3
Log rotated successfully.
```

## Note

This implementation uses POSIX-style `stat()` available on Linux/macOS and supported by common MinGW environments on Windows.
