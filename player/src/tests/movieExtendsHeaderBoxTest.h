/************************************************************************************
* Copyright (c) 2013 ONVIF.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright
*      notice, this list of conditions and the following disclaimer in the
*      documentation and/or other materials provided with the distribution.
*    * Neither the name of ONVIF nor the names of its contributors may be
*      used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL ONVIF BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
************************************************************************************/
#ifndef MOVIEEXTENDSHEADERBOXTEST_H
#define MOVIEEXTENDSHEADERBOXTEST_H

#include "boxTestsCommon.h"

template< typename DATA_TYPE >
class MovieExtendsHeaderBoxTest
{
public:
    explicit MovieExtendsHeaderBoxTest() {}

    void localTest_data();
    void localTest();
};


class MovieExtendsHeaderBoxTest64
     : public QObject, public MovieExtendsHeaderBoxTest<uint64_t>
{
    Q_OBJECT

public:

private Q_SLOTS:
    void readingTest_data();
    void readingTest();
};

class MovieExtendsHeaderBoxTest32
     : public QObject, public MovieExtendsHeaderBoxTest<uint32_t>
{
    Q_OBJECT

public:

private Q_SLOTS:
    void readingTest_data();
    void readingTest();
};

#endif // MOVIEEXTENDSHEADERBOXTEST_H
