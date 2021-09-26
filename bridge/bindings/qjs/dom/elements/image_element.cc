/*
 * Copyright (C) 2021 Alibaba Inc. All rights reserved.
 * Author: Kraken Team.
 */

#include "image_element.h"
#include "bridge_qjs.h"
#include "bindings/qjs/qjs_patch.h"

namespace kraken::binding::qjs {

ImageElement::ImageElement(JSContext *context) : Element(context) {}

void bindImageElement(std::unique_ptr<JSContext> &context) {
  auto *constructor = ImageElement::instance(context.get());
  context->defineGlobalProperty("HTMLImageElement", constructor->classObject);
  context->defineGlobalProperty("Image", JS_DupValue(context->ctx(), constructor->classObject));
}

OBJECT_INSTANCE_IMPL(ImageElement);

JSValue ImageElement::instanceConstructor(QjsContext *ctx, JSValue func_obj, JSValue this_val, int argc, JSValue *argv) {
  auto instance = new ImageElementInstance(this);
  return instance->instanceObject;
}
PROP_GETTER(ImageElementInstance, width)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getWidth", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, width)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  std::string key = "width";
  NativeString *args_01 = stringToNativeString(key);
  NativeString *args_02 = jsValueToNativeString(ctx, argv[0]);
  foundation::UICommandBuffer::instance(element->m_context->getContextId())
    ->addCommand(element->eventTargetId, UICommand::setProperty, *args_01, *args_02, nullptr);
  return JS_NULL;
}
PROP_GETTER(ImageElementInstance, height)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getHeight", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, height)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  std::string key = "height";
  NativeString *args_01 = stringToNativeString(key);
  NativeString *args_02 = jsValueToNativeString(ctx, argv[0]);
  foundation::UICommandBuffer::instance(element->m_context->getContextId())
    ->addCommand(element->eventTargetId, UICommand::setProperty, *args_01, *args_02, nullptr);
  return JS_NULL;
}
PROP_GETTER(ImageElementInstance, naturalWidth)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getNaturalWidth", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, naturalWidth)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  return JS_NULL;
}
PROP_GETTER(ImageElementInstance, naturalHeight)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getNaturalHeight", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, naturalHeight)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  return JS_NULL;
}
PROP_GETTER(ImageElementInstance, src)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getSrc", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, src)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  std::string key = "src";
  NativeString *args_01 = stringToNativeString(key);
  NativeString *args_02 = jsValueToNativeString(ctx, argv[0]);
  foundation::UICommandBuffer::instance(element->m_context->getContextId())
    ->addCommand(element->eventTargetId, UICommand::setProperty, *args_01, *args_02, nullptr);
  return JS_NULL;
}
PROP_GETTER(ImageElementInstance, loading)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  getDartMethod()->flushUICommand();
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  return element->callNativeMethods("getLoading", 0, nullptr);
}
PROP_SETTER(ImageElementInstance, loading)(QjsContext *ctx, JSValue this_val, int argc, JSValue *argv) {
  auto *element = static_cast<ImageElementInstance *>(JS_GetOpaque(this_val, Element::classId()));
  std::string key = "loading";
  NativeString *args_01 = stringToNativeString(key);
  NativeString *args_02 = jsValueToNativeString(ctx, argv[0]);
  foundation::UICommandBuffer::instance(element->m_context->getContextId())
    ->addCommand(element->eventTargetId, UICommand::setProperty, *args_01, *args_02, nullptr);
  return JS_NULL;
}

ImageElementInstance::ImageElementInstance(ImageElement *element): ElementInstance(element, "img", true) {
}

bool ImageElementInstance::dispatchEvent(EventInstance *event) {
  std::u16string u16EventType = std::u16string(reinterpret_cast<const char16_t *>(event->nativeEvent->type->string),
                                               event->nativeEvent->type->length);
  std::string eventType = toUTF8(u16EventType);
  bool result = EventTargetInstance::dispatchEvent(event);

  return result;
}

void ImageElementInstance::protectImageInstance() {
  JS_DupValue(m_ctx, instanceObject);
}

void ImageElementInstance::freeImageInstance() {
  JS_FreeValue(m_ctx, instanceObject);
}

}
