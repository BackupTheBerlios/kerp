Drop table partner;
create table partner(
id serial not null primary key,
name varchar (64),
surename varchar(64),
city integer references city ,
accountno char(4),
credit int4
);


