Drop table invoice_line;
Drop sequence invoice_line_id_seq;
create table invoice_line(
id serial not null,
invoice_id int not null references invoice (id),
product_id int not null references product ,
price int not null,
quantity int not null,
discount float default 0 check(discount<=1),
tax	float default 0  check(tax<=1));
