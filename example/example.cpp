#include <iostream>
#include <string>

#include <derivejson/derivejson.hpp>
#include <nlohmann/json.hpp>


namespace example {

DEFINE_MODEL(
    Vin,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

}

int main() {
    using json = nlohmann::json;

    json j = json::parse("{\"txid\":\"0x12312\",\"vout\":3}");
    example::Vin vin_deserialize = j;

    std::cout << vin_deserialize.transaction_id << std::endl;
    std::cout << vin_deserialize.vout << std::endl;

    json j_serialize = vin_deserialize;
    std::cout << j_serialize.dump() << std::endl;
}
