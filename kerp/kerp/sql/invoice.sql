Drop table invoice;
Drop sequence invoice_id_seq;

create table invoice (
id serial not null,
invoice_id int4 not null primary key,
customer_id int4 not null references partner,
invoice_date date,
productTransId int4  references product_trans
);

insert into invoice (select nextval('invoice_id_seq'),1,26,'20030101');
insert into invoice (select nextval('invoice_id_seq'),2,40,'20030101');
insert into invoice (select nextval('invoice_id_seq'),3,42,'20030119');
