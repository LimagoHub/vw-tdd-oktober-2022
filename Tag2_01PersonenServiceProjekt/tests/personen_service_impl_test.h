//
// Created by JoachimWagner on 11.10.2022.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockpersonen_repository.h"
#include "Mockblacklist_service.h"
#include "../source/persistence/person.h"
#include "../source/service/personen_service_impl.h"
#include "../source/service/personen_service_exception.h"


using namespace testing;
class personen_service_impl_test: public Test
{
protected:
    Mockblacklist_service blacklistMock;
    Mockpersonen_repository repoMock;
    personen_service_impl object_under_test{repoMock, blacklistMock};
};