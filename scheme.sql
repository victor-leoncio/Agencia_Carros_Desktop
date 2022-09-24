create table agencia (
    cod_setor int unsigned not null auto_increment,
    nome varchar(50) not null,
    primary key(cod_setor)
);

create table carros (
	cod_carro int unsigned not null auto_increment,
	nome varchar(50) not null,
	modelo varchar(50) not null,
	ano varchar(4) not null,
	valor int unsigned not null,
	qtd_estoque int unsigned not null,
	cod_setor int unsigned not null,
	primary key(cod_carro, cod_setor),
	foreign key(cod_setor) references agencia(cod_setor)
);

create table pecas (
	cod_pecas int unsigned not null auto_increment,
	nome varchar(50) not null,
	valor int unsigned not null,
	qtd_estoque int unsigned not null,
	cod_setor int unsigned not null,
	primary key(cod_pecas, cod_setor),
	foreign key(cod_setor) references agencia(cod_setor)
);

create table funcionarios (
	CPF_funcionario varchar(11) not null,
	nome varchar(50) not null,
	endereco varchar(50) not null,
	salario int unsigned not null,
	cod_setor int unsigned not null,
	primary key(CPF_funcionario, cod_setor),
	foreign key(cod_setor) references agencia(cod_setor)
);

create table clientes (
	CPF_cliente varchar(11) not null,
	nome varchar(50) not null,
	telefone varchar(15) not null,
	endereco varchar(50) not null,
	placa_do_carro varchar(7) not null,
	CPF_funcionario varchar(11) not null,
	primary key(CPF_cliente, CPF_funcionario),
	unique(placa_do_carro),
	foreign key(CPF_funcionario) references funcionarios(CPF_funcionario)
);

create table vendas (
	id int unsigned not null auto_increment,
	CPF_cliente varchar(11) not null,	
	cod_carro int unsigned not null,
	data_venda date not null,
	primary key(id, CPF_cliente, cod_carro),
	foreign key(CPF_cliente) references clientes(CPF_cliente),
	foreign key(cod_carro) references carros(cod_carro)
);

create table trocas (
	id int unsigned not null auto_increment,
	CPF_cliente varchar(11) not null,
	cod_carro_antigo int unsigned not null,
	cod_carro_novo int unsigned not null,
	data_troca date not null,
	primary key(id, CPF_cliente, cod_carro_antigo, cod_carro_novo),
	foreign key(CPF_cliente) references clientes(CPF_cliente),
	foreign key(cod_carro_antigo) references carros(cod_carro),
	foreign key(cod_carro_novo) references carros(cod_carro)
);

create table revisao (
	id int unsigned not null auto_increment,
	CPF_cliente varchar(11) not null,
	cod_carro int unsigned not null,
	data_revisao date not null,
	primary key(id, CPF_cliente, cod_carro),
	foreign key(CPF_cliente) references clientes(CPF_cliente),
	foreign key(cod_carro) references carros(cod_carro)
);

create table pecas_pagas (
	id int unsigned not null,
	cod_pecas int unsigned not null,
	primary key(id, cod_pecas),
	foreign key(id) references revisao(id),
	foreign key(cod_pecas) references pecas(cod_pecas)
);
