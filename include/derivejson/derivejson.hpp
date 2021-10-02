#ifndef DERIVEJSON_HPP
#define DERIVEJSON_HPP

#pragma once

#include <boost/preprocessor.hpp>

#define CREATE_MY_MACRO_PLACEHOLDER_FILLER_0(X, Y, Z) \
  ((X, Y, Z)) CREATE_MY_MACRO_PLACEHOLDER_FILLER_1
#define CREATE_MY_MACRO_PLACEHOLDER_FILLER_1(X, Y, Z) \
  ((X, Y, Z)) CREATE_MY_MACRO_PLACEHOLDER_FILLER_0
#define CREATE_MY_MACRO_PLACEHOLDER_FILLER_0_END
#define CREATE_MY_MACRO_PLACEHOLDER_FILLER_1_END

#define DECLARE_DATA_MEMBER(R, _, TYPE_AND_NAME)                        \
  BOOST_PP_TUPLE_ELEM(3, 0, TYPE_AND_NAME) BOOST_PP_TUPLE_ELEM(3, 1, TYPE_AND_NAME);

#define DEFINE_SERIALIZATION_ELEMENT(R, _, TYPE_AND_NAME)               \
  { BOOST_PP_TUPLE_ELEM(3, 2, TYPE_AND_NAME), o.BOOST_PP_TUPLE_ELEM(3, 1, TYPE_AND_NAME) },

#define DEFINE_DESERIALIZATION_ELEMENT(R, _, TYPE_AND_NAME)             \
  o.BOOST_PP_TUPLE_ELEM(3, 1, TYPE_AND_NAME) = j.at(BOOST_PP_TUPLE_ELEM(3, 2, TYPE_AND_NAME)).get<BOOST_PP_TUPLE_ELEM(3, 0, TYPE_AND_NAME)>();

#define DEFINE_EQUAL_OPERATOR_ELEM(R, _, TYPE_AND_NAME)                 \
  lhs.BOOST_PP_TUPLE_ELEM(3, 1, TYPE_AND_NAME) == rhs.BOOST_PP_TUPLE_ELEM(3, 1, TYPE_AND_NAME) &&

#define DEFINE_MODEL(NAME, TYPES_AND_NAMES)                             \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void to_json(nlohmann::json& j, const NAME& o) {                                \
    j = nlohmann::json{BOOST_PP_SEQ_FOR_EACH(DEFINE_SERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END))}; \
  }                                                                     \
  void from_json(const nlohmann::json& j, NAME& o) {                              \
    BOOST_PP_SEQ_FOR_EACH(DEFINE_DESERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  }                                                                     \
  bool operator ==(const NAME& lhs, const NAME& rhs) {                  \
    return BOOST_PP_SEQ_FOR_EACH(DEFINE_EQUAL_OPERATOR_ELEM, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) true; \
  }

#define DEFINE_MODEL_JSON(NAME, TYPES_AND_NAMES)                        \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void to_json(nlohmann::json& j, const NAME& o) {                                \
    j = nlohmann::json{BOOST_PP_SEQ_FOR_EACH(DEFINE_SERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END))}; \
  }                                                                     \
  void from_json(const nlohmann::json& j, NAME& o) {                              \
    BOOST_PP_SEQ_FOR_EACH(DEFINE_DESERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  }

#define DEFINE_MODEL_TO_JSON(NAME, TYPES_AND_NAMES)                     \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void to_json(nlohmann::json& j, const NAME& o) {                                \
    j = nlohmann::json{BOOST_PP_SEQ_FOR_EACH(DEFINE_SERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END))}; \
  }                                                                     \
  bool operator ==(const NAME& lhs, const NAME& rhs) {                  \
    return BOOST_PP_SEQ_FOR_EACH(DEFINE_EQUAL_OPERATOR_ELEM, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) true; \
  }

#define DEFINE_MODEL_FROM_JSON(NAME, TYPES_AND_NAMES)                   \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void from_json(const nlohmann::json& j, NAME& o) {                              \
    BOOST_PP_SEQ_FOR_EACH(DEFINE_DESERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
      }                                                                 \
  bool operator ==(const NAME& lhs, const NAME& rhs) {                  \
    return BOOST_PP_SEQ_FOR_EACH(DEFINE_EQUAL_OPERATOR_ELEM, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) true; \
  }

#define DEFINE_MODEL_TO_JSON_RAW(NAME, TYPES_AND_NAMES)                 \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void to_json(nlohmann::json& j, const NAME& o) {                                \
    j = nlohmann::json{BOOST_PP_SEQ_FOR_EACH(DEFINE_SERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END))}; \
  }

#define DEFINE_MODEL_FROM_JSON_RAW(NAME, TYPES_AND_NAMES)               \
  struct NAME {                                                         \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_DATA_MEMBER, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  };                                                                    \
  void from_json(const nlohmann::json& j, NAME& o) {                              \
    BOOST_PP_SEQ_FOR_EACH(DEFINE_DESERIALIZATION_ELEMENT, _, BOOST_PP_CAT(CREATE_MY_MACRO_PLACEHOLDER_FILLER_0 TYPES_AND_NAMES,_END)) \
  }

#endif /* DERIVEJSON_HPP */
