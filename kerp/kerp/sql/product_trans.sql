Drop table product_trans;
Drop sequence product_trans_id_seq;
create table product_trans (
id serial not null primary key,
type char(8),
transdate date,
placefrom int4 not null,
placeto int4 not null
);
