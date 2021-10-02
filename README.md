# Automatically generate JSON serializers and deserializers

## Forked from

- [Original library](https://github.com/trading-rs/derive-json-cpp)

## Getting Started

### Required

**CMake** 3.10.0 or higher for building  
**nlohmann_json** 3.2.0  
**Boost** 1.76 or higher  
**GoogleTest** 1.10 for tests  

### Build

```sh
git clone https://github.com/Exerros/derive-json-cpp
mkdir build
cd build
cmake ..
cmake --build .
```

### Build with test  
  
For build with example or tests, add key to cmake call.

```sh
cmake .. -DDERIVEJSON_BUILD_EXAMPLE=ON
cmake .. -DDERIVEJSON_BUILD_TESTS=ON
```

Also, if you plan to build with tests, you need to call the folowing commands to
load the external cmake module.

```sh
git submodule init
git submodule update
```

### Examples

```C++
#include <iostream>
#include <string>

#include <derivejson/derivejson.hpp>
#include <nlohmann/json.hpp>

namespace example_model {

DEFINE_MODEL(
    Vin,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

}

int main() {
    using json = nlohmann::json;

    json j = json::parse("{\"txid\":\"0x12312\",\"vout\":3}");
    example_model::Vin vin_deserialize = j;

    std::cout << vin_deserialize.transaction_id << std::endl;
    std::cout << vin_deserialize.vout << std::endl;

    json j_serialize = vin_deserialize;
    std::cout << j_serialize.dump() << std::endl;
}
```

