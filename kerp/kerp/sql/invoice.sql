Drop table invoice;
Drop sequence invoice_id_seq;

create table invoice (
id serial not null,
invoice_id int4 not null primary key,
customer_id char(8) not null references partner,
invoice_date date
);

insert into invoice (select nextval('invoice_id_seq'),1,'10101010','20030101');

insert into invoice (select nextval('invoice_id_seq'),2,'10101011','20030119');
insert into invoice (select nextval('invoice_id_seq'),3,'10101010','20030119');
