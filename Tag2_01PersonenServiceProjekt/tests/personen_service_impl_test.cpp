//
// Created by JoachimWagner on 11.10.2022.
//

#include "personen_service_impl_test.h"

#include "personen_service_impl_test.h"
#include "stdexcept"
person valid_person{ "Jane","Doe" };

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception)
{
    try {
        person not_valid_person{ "J", "Doe" };
        object_under_test.speichern(not_valid_person);
        FAIL() << "unerwartet keine Exception";
    } catch (personen_service_exception& ex)
    {
        EXPECT_STREQ("Vorname zu kurz", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception)
{
    try {
        person not_valid_person{ "John", "D" };
        object_under_test.speichern(not_valid_person);
        FAIL() << "unerwartet keine Exception";
    }
    catch (personen_service_exception& ex)
    {
        EXPECT_STREQ("Nachname zu kurz", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__Unerwuenschte_Person__throws_personen_service_exception)
{
    try {

        EXPECT_CALL(blacklistMock, is_blacklisted(valid_person)).WillOnce(Return(true));
        object_under_test.speichern(valid_person);
        FAIL() << "unerwartet keine Exception";
    }
    catch (personen_service_exception& ex)
    {
        EXPECT_STREQ("Antipath", ex.what());
    }
}
TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_service__throws_personen_service_exception)
{
    try {
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(Throw(std::out_of_range{ "Dummy"})));
        object_under_test.speichern(valid_person);
        FAIL() << "unerwartet keine Exception";
    }
    catch (personen_service_exception& ex)
    {
        EXPECT_STREQ("Fehler beim Speichern", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repository)
{
    InSequence s;

    // Arrange
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(valid_person));


    object_under_test.speichern(valid_person);


}

TEST_F(personen_service_impl_test, speichern_overloaded__happy_day__person_passed_to_repository)
{

    person person_param_to_catch;

    // Arrange
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&person_param_to_catch)));
   /* EXPECT_CALL(repoMock, save_or_update(_)).WillOnce([this](const person &p){

    });*/
    object_under_test.speichern("Max","Mustermann");

    EXPECT_EQ("Max", person_param_to_catch.get_vorname());
    EXPECT_EQ("Mustermann", person_param_to_catch.get_nachname());
}
