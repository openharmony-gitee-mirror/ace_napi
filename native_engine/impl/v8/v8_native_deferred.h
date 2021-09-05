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

#ifndef FOUNDATION_ACE_NAPI_NATIVE_ENGINE_V8_NATIVE_DEFERRED_H
#define FOUNDATION_ACE_NAPI_NATIVE_ENGINE_V8_NATIVE_DEFERRED_H

#include "v8_headers.h"

#include "native_engine/native_deferred.h"

class V8NativeDeferred : public NativeDeferred {
public:
    V8NativeDeferred(V8NativeEngine* engine, v8::Local<v8::Promise::Resolver> deferred);
    virtual ~V8NativeDeferred();
    virtual void Resolve(NativeValue* data) override;
    virtual void Reject(NativeValue* reason) override;

private:
    V8NativeEngine* engine_;
    v8::Global<v8::Promise::Resolver> deferred_;
};

#endif /* FOUNDATION_ACE_NAPI_NATIVE_ENGINE_V8_NATIVE_DEFERRED_H */