(select p.firstName, p.lastName, a.city, a.state
from person p, address a 
where p.personId = a.personId) 
union
(select p.firstName, p.lastName, null, null
from person p
where p.personId not in (
    select personId from address
));