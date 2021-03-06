/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "v8_native_external.h"
#include "v8_native_reference.h"

V8NativeExternal::V8NativeExternal(V8NativeEngine* engine, void* value, NativeFinalize callback, void* hint)
    : V8NativeExternal(engine, v8::External::New(engine->GetIsolate(), value))
{
}

V8NativeExternal::V8NativeExternal(V8NativeEngine* engine, v8::Local<v8::Value> value) : V8NativeValue(engine, value) {}

V8NativeExternal::~V8NativeExternal() {}

void* V8NativeExternal::GetInterface(int interfaceId)
{
    return (NativeExternal::INTERFACE_ID == interfaceId) ? (NativeExternal*)this : nullptr;
}

V8NativeExternal::operator void*()
{
    v8::Local<v8::External> value = value_;
    return value->Value();
}
