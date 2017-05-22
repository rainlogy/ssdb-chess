/*
  Copyright (c) 2012-2014 The SSDB Authors. All rights reserved.
  Use of this source code is governed by a BSD-style license that can be
  found in the LICENSE file.
*/
#ifndef SSDB_HASH_H_
#define SSDB_HASH_H_

#include "../include.h"
#include "ssdb_impl.h"

static const int kKeyByteLen = 1;
static const int kFieldByteLen = 1;
static const int kValueByteLen = 1;
static const int kTotalByteLen = 2;

std::string encode_hash_key(const Bytes &key);

int decode_hash_key(const Bytes &slice, std::string *key);

std::string encode_hash_value(const Bytes &field, const Bytes &value);

int decode_hash_value(const Bytes& slice, std::string* field, std::string* value);

// TBD(kg): string op should be optimized
int insert_update_hash_value(const Bytes& slice, const Bytes& field,
			     const Bytes& value, std::string* ret);
// -1: error
// 0: not exist
// 1: done
int remove_hash_value(const Bytes& slice, const Bytes& field,
		      std::string* ret);
int get_hash_value(const Bytes& slice, const Bytes& field, std::string* value);

int get_hash_values(const Bytes& slice, std::deque<StrPair>& values);

int get_hash_value_count(const Bytes& slice);

int TEST_insert_update_hash_value(const Bytes& slice, const Bytes& field, const Bytes& value,
					 std::string* ret);

int TEST_remove_hash_value(const Bytes& slice, const Bytes& field,
			   std::string* ret);

int TEST_get_hash_values(const Bytes& slice, std::vector<StrPair>& values);

int TEST_get_hash_value_count(const Bytes& slice);

#endif
