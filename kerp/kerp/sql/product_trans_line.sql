Drop table product_trans_line;
Drop sequence product_trans_line_id_seq;

Create table product_trans_line (
id serial not null primary key,
product_id int4 not null,
quantity float not null,
price int4 default 0
);
