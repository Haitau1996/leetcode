SELECT Person.firstName, Person.lastName,
    Address.city, Address.state
FROM Person left Join Address
on Person.PersonId = Address.PersonId;
