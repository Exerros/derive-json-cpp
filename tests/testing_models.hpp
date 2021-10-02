#ifndef DERIVE_JSON_TESTING_MODELS_HPP
#define DERIVE_JSON_TESTING_MODELS_HPP

#pragma once

#include <string>

#include <nlohmann/json.hpp>
#include <derivejson/derivejson.hpp>

namespace tests {
namespace models {

DEFINE_MODEL(
    Vin,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

DEFINE_MODEL_JSON(
    VinJSON,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

DEFINE_MODEL_TO_JSON(
    VinToJSON,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

DEFINE_MODEL_FROM_JSON(
    VinFromJSON,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

DEFINE_MODEL_TO_JSON_RAW(
    VinToJSONRaw,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

DEFINE_MODEL_FROM_JSON_RAW(
    VinFromJSONRaw,
    (std::string, transaction_id, "txid")
    (int,         vout,           "vout")
)

} /* namespace models */
} /* namespace tests */

#endif /* DERIVE_JSON_TESTING_MODELS_HPP */
