Drop Table product;
Drop sequence product_id_seq;
create table product(
id serial not null primary key,
product_id char(8) not null,
name varchar(128) not null ,
price int4 not null);
insert into product (product_id,name,price) values ('11111111','testing product',1234);

