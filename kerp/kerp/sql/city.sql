Drop table city;
Drop sequence city_id_seq;

create table city(
id serial not null primary key,
province_id int,
name varchar(64) not null, 
constraint city_province foreign key (province_id) references province (id) match full);
