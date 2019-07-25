#include "elements.hpp"

#include <string>
#include <vector>
#include <map>
#include <assert.h>

using std::string;
using std::map;

namespace webio {

Json FrontEndElement::Export() const {
  Json output;
  map<string, Json> json_fields;

  if (true) { // ToDo(Saharsh): replace by HasChildren()
    std::vector<Json> children1;  // ToDo(Saharsh): fix this shit
    for (auto &child: children) {
      children1.push_back(std::move(child.Export()));
    }
    json_fields["children"] = Json(std::move(children1));
  }

  json_fields["element_type"] = ElementTypeString(this->element_type);

  if (this->has_icon) {
    json_fields["icon"] = Json(icon_);
  }

  if (this->has_text_string) {
    json_fields["text_string"] = Json(text_string_);
  }

  if (this->has_label_string) {
    json_fields["label_string"] = Json(label_string_);
  }

  if (this->has_color_theme) {
    json_fields["color_theme"] = Json(color_theme_);
  }

  if (this->has_font_size) {
    json_fields["font_size"] = Json(font_size_);
  }

  if (this->has_margin) {
    json_fields["margin"] = Json(margin_);
  }

  if (this->has_height) {
    json_fields["height"] = Json(height_);
  }

  if (this->has_width) {
    json_fields["width"] = Json(width_);
  }

  if (this->has_padding) {
    json_fields["padding"] = Json(padding_);
  }

  if (this->has_border_width) {
    json_fields["border_width"] = Json(border_width_);
  }

  if (this->has_value_integer) {
    json_fields["value_integer"] = Json(value_integer_);
  }

  if (this->has_default_rows) {
    json_fields["default_rows"] = Json(default_rows_);
  }

  if (this->has_selected_tab) {
    json_fields["selected_tab"] = Json(selected_tab_);
  }

  if (this->has_disabled) {
    json_fields["disabled"] = Json(disabled_);
  }

  if (this->has_allow_multiple) {
    json_fields["allow_multiple"] = Json(allow_multiple_);
  }

  if (this->has_options) {
    std::vector<Json> json_string_values;
    for (const std::string& option : options_) {
      json_string_values.push_back(Json(option));
    }
    json_fields["options"] = Json(std::move(json_string_values));
  }

  if (this->has_src) {
    json_fields["src"] = Json(src_);
  }

  output.Set(json_fields);
//  output.Set(unordered_map{
//    {"element_type", Json("BUTTON")},
//    {"element_id", Json(12)},
//    {"onclick_id", Json(JSON::NULL_TYPE)},
//    {"icon", Json()},
//    {"label_string": "Click Me"}});
  return output;
}

} // namespace webio