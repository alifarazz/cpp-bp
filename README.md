- Build project
  * Debug 
    ``` sh
    $ mkdir build-debug
    $ cmake -DCMAKE_BUILD_TYPE=Debug -B build-debug -S .
    $ cmake --build build-debug -t main_library
    $ cmake --build build-debug -t help  # for more info about targets
    ```

  * Release 
    ``` sh
    $ mkdir build-release
    $ cmake -DCMAKE_BUILD_TYPE=Release -B build-release -S .
    $ cmake --build build-release -t all  # build everything!!!
    ```

  * Development
    ``` sh
    $ mkdir build-dev
    $ cmake -DCMAKE_BUILD_TYPE=??? -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -B build-dev -S .
    $ cmake --build build-dev -t all  # build everything!!!
    $ ln -s $PWD/build-dev/compile_commands.json $PWD/compile_commands.json
    ```

- Tests
  ``` sh
  $ cmake --build build* -t testlib  # build tests
  $ cmake --build build* -t test  # run tests
  ```

- DOC (not yet ready)
  ``` sh
  $ cmake --build build* -t doc
  ```

---
  
#### Credits
Based on [modern-cmake](https://cliutils.gitlab.io/modern-cmake/), specifically [this](https://gitlab.com/CLIUtils/modern-cmake/-/tree/master/examples/extended-project).
