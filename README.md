# My leetcode source test container


## 1 container for C/C++
```
    % docker build -f Dockerfile.cpp -t leet-code-cpp .
    % Docker run --rm -it --entrypoint bash -v `pwd`:/App/src  leet-code-cpp
```