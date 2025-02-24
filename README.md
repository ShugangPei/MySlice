# MySlicer

MySlicer 是一个基于CuraEngine的切片软件模块，能够读取和处理STL文件，并输出所有的顶点和面片基本信息。

## 功能

- 读取二进制格式的STL文件
- 输出顶点和面片的基本信息到TXT文件

## 构建和运行

### 条件

- CMake 3.10 或更高版本
- C++14 编译器

### 构建

```sh
mkdir build
cd build
cmake ..
make
```

### 运行

```sh
./MySlicer path/to/your/model.stl output.txt
```

## 许可证

该项目使用 [GNU Affero General Public License v3.0](LICENSE) 许可证。
