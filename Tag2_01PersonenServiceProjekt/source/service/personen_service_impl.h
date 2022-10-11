#pragma once
#include "../persistence/person.h"
#include "../persistence/personen_repository.h"
#include "../service/personen_service_exception.h"
#include "../service/blacklist_service.h"

class personen_service_impl {

    personen_repository& repo;
    blacklist_service &blacklist_service_;

    void validate_person(person& person_) const
    {
        if (person_.get_vorname().length() < 2)
            throw personen_service_exception("Vorname zu kurz");

        if (person_.get_nachname().length() < 2)
            throw personen_service_exception("Nachname zu kurz");
    }

    void business_check(person& person_) const
    {
        if (blacklist_service_.is_blacklisted(person_))
            throw personen_service_exception("Antipath");
    }

    void check_person(person& person_) const
    {
        validate_person(person_);
        business_check(person_);
    }

    void speichern_impl(person& person_) const
    {
        check_person(person_);
        repo.save_or_update(person_);
    }


public:


    personen_service_impl(personen_repository& repo, blacklist_service& blacklist_service)
            : repo(repo),
              blacklist_service_(blacklist_service)
    {
    }

    /*
     *	Vorname < 2 -> PSE
     *	Nachname < 2 -> PSE
     *
     *	Attila -> PSE
     *
     *	Alle Technische Exceptions -> PSE
     *
     *	Happy Day -> person an Save Methode �bergeben
     *
     */
    void speichern(person& person_) const
    {
        try {
            speichern_impl(person_);
        } catch(personen_service_exception &p)
        {
            throw p;
        } catch (std::exception & ex)
        {
            // Log ex
            throw personen_service_exception{ "Fehler beim Speichern"};
        }

    }

    void speichern(std::string vorname,std::string nachname) const
    {
        speichern(person{ vorname, nachname });

    }
};
