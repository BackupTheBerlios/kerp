Drop sequence manualids_id_seq;
Drop Table manualids;
create table manualids (
id serial not null,
tablename varchar(64) not null,
seq int4 not null);
