# Simple database managment

## Features

- Login
- SQL-like query language parser.
- In-memory data storage with basic indexing.
- Basic CRUD (Create, Read, Update, Delete) operations.

## Setup (Linux)

`sudo apt update`
`sudo apt install build-essential gdb`
`gcc --version`

`sudo apt-get install sqlite3 libsqlite3-dev`

`g++ -o login login.cpp -lsqlite3`
`/login`
