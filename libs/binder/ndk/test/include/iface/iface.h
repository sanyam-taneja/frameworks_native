/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <android/binder_ibinder.h>
#include <utils/RefBase.h>

class IFoo : public virtual ::android::RefBase {
public:
    static const char* kSomeInstanceName;
    static AIBinder_Class* kClass;

    // Takes ownership of IFoo
    binder_status_t addService(const char* instance);
    static ::android::sp<IFoo> getService(const char* instance);

    enum Call {
        DOFOO = FIRST_CALL_TRANSACTION + 0,
    };

    virtual ~IFoo();
    virtual int32_t doubleNumber(int32_t in) = 0;

private:
    AIBinder_Weak* mWeakBinder = nullptr; // maybe owns AIBinder
};
