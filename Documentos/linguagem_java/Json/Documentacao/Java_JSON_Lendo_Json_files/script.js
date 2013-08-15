try{
function loadCssHOTWords(filename){
var fileref=document.createElement("link");
fileref.setAttribute("rel", "stylesheet");
fileref.setAttribute("type", "text/css");
fileref.setAttribute("href", filename);
var head = document.getElementsByTagName('head')[0];
if (head != null) {
if (head.firstChild != null) {
head.insertBefore(fileref, head.lastChild);
} else {
head.appendChild(fileref);
}
}
}
function css_start(){
loadCssHOTWords('http://img.hotwords.com.br/img/hw_csspadrao_0_v15.css');
var imgBalaoBG = new Image;
imgBalaoBG.src = "http://img.hotwords.com.br/img/balao_0_gif.gif";
}
var hotwordsEliminaDesaparecerXY = true; 
var qtdAnuncios=0;
var maxQtdAnuncios= 4;
var tek=true;
function hideBL(divids){ 
var divids2 = 'HOTWordsTitle';
if (divids2 != undefined){ 
var ziob = document.getElementById(divids2);
if (ziob != undefined){ 
ziob.style.visibility='hidden'; 
var ziob2 = document.getElementById(divids2 + 'Text'); 
if (ziob2 != undefined){
ziob2.innerHTML = ''; 
}
}
}
}
function hideTitle(s) {
if(!hotwordsEliminaDesaparecerXY){return; }
if (this.tek){ return; }
window.status = '';
hideBL(s);
hotwordsEliminaDesaparecerXY = true;
}
function showSure() {this.tek=true;}
function hideMaybe(s, p){
this.tek=false;
setTimeout("hideTitle('" + s + "')",500);
}
function detectarFlashInstall() {
var flashinstalled = 0;
var flashversion = 0;
if(navigator.plugins && navigator.plugins.length){
x = navigator.plugins["Shockwave Flash"];
if (x){
flashinstalled = 2;
if (x.description){
y = x.description;
flashversion = y.charAt(y.indexOf('.')-1);
}
}
else{
if (navigator.plugins["Shockwave Flash 2.0"]){
flashinstalled = 2;
}
}
}
else if (navigator.mimeTypes && navigator.mimeTypes.length){
x = navigator.mimeTypes['application/x-shockwave-flash'];
if (x && x.enabledPlugin){
flashinstalled = 2;
}
else{
flashinstalled = 1;
}
}
else {
if((navigator.appName == "Microsoft Internet Explorer") && 
(navigator.appVersion.indexOf("Mac") == -1 && navigator.appVersion.indexOf("3.1") == -1)
 || (navigator.plugins && navigator.plugins["Shockwave Flash"])){
try{
var axo = new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7");
var version = axo.GetVariable("$version");
var temp1q2w2 = version.split(",");
var temp1q2w = temp1q2w2[0].split(" ");
if(temp1q2w[1] >= 7){
flashinstalled = 2;
}
else{
flashinstalled = 0;
}
}catch(e){}
}
else{
flashinstalled = 0;
}
}

return flashinstalled;
}
var tempFlashWH = detectarFlashInstall();
var d=document;
var hwPal = {};
if (typeof(hwPals)=="undefined"){
hwPal.count = 1;
var hwPals = {};
}
hwPal.tr = 0;
hwPal.smalPals=function(h){
return h.toLowerCase();
}
hwPal.inifirstSmalPals=function(h){
var t = h.toLowerCase();
t = t.substr(0, t.length-1);
return t;
}
hwPal.fimfirstSmalPals=function(h){
var t = h.toLowerCase();
t = t.substr(1, t.length);
return t;
}
hwPal.firstSmalPals=function(h){
var t = h.toLowerCase();
t = t.substr(1, t.length);
t = t.substr(0, t.length-1);
return t;
}
hwPal.hotwords0 = "";
hwPal.hotwords1 = "servico exclusivo|aplicacao financeira|cheques|transacoes financeiras|servico personalizado|central do banco|banco personalizado|atendimento vip|banco moderno|banco diferenciado|capital financeiro|transacao bancaria|equipe exclusiva|pagamento|atendimento moderno|movimentacao economica|servico inovador|banco do brasil|comodidade|recurso economico|central de atendimento|confianca|atendimento inovador|gerente do banco|seguranca|bancario|recurso financeiro|clientes|bb estilo|movimentacao bancaria|cliente|valor|assessoria financeira|servico diferenciado|equipe bancaria|dinheiros|produto diferenciado|banco unico|gerentes|personalite|lucro|financeiros|equipe do banco|cheque|perfil do cliente|tranquilidade|financeiro|aplicacoes financeiras|assessoria economica|equipe de profissionais|bancarios|atendimento diferenciado|credibilidade|financeiras|servico moderno|financeira|pagamentos|lucros|privacidade|financas|valores|confiabilidade|bancaria|conta corrente|movimentacao financeira|gerente|inovador|central bancaria|patrimonios|banco bb estilo|banco inovador|sofisticacao|conforto|capital de giro|transacao financeira|dinheiro|taloes de cheque|atendimento exclusivo|talao de heque|transacoes bancarias|bancarias|financa|banco sofisticado|produto personalizado";
hwPal.hotwords2 = "dicas de jogos|campeao|truques|jogos de humor|emocionante|interativa|templarios|desenho|personagens|aventuras|desafio|brincadeiras|interativo|baixar jogos|jogos de motos|games on line|games dinamicos|feiticeiros|games surpreendentes|jogos de emulador|pontuacoes|jogos masculinos|desafiador|vencer|games em flash|jogos de aventura|dicas de games|pan gu|premios|internautas|animada|games imperdiveis|emulador|magia|jogos populares|animado|fliperama|desenvolvidas|personagem|games free|games de carro|jogos de damas|games de aventura|digital|desafiar|games de humor|games radicais|guerreiras|desafiadoras|emocionantes|enigmas|video games|jogos de playstation|games de corrida|on line|premiacoes|jogos de guerra|games de estrategia|games de acao|adversarios|competicao|fa|jogos de xbox|games legais|divirta-se|barbaros|jogos de meninas|jogos de espionagem|magicas|jogos de esporte|interatividade|games de naves|avancados|games classicos|games de pc|jogos de rpg on line|games educativos|jogos de enigma|campeonatos|jovem|desafiante|jogos surpreendentes|jogue|jogabilidade|jogos rpg|avancadas|games de esporte|games engracados|player|jogos|games de baixar|herois|videogame|games de espionagem|infantis|guerreiros|premiadas|games impressionantes|jogos de corrida|adversarias|interatividades|estrategia|games online|competidora|heroi|games de cartas|games de terror|emuladores|premiacao|vencedor|se divertir|torneio|disputa|jogabilidades|competir|estrategias|desenvolvido|fas|jogos engracados|games de meninas|premiados|consoles|baixar games|jogos otimos|desenvolvida|ganhador|bonus|disputas|desafiantes|jogos free|jogos gratis|brinca|jogadora|usuario|jogos incriveis|consolas|games incriveis|games de guerra|usuaria|games da hora|misteriosa|jogos de rpg online|gratuito|misterio|divirta se|jogos on line|desafiadores|digitais|games gratis|magica|games emocionantes|jogos de terror|ganhadora|vencendo|divertir-se|mitologia|equipes|games belicos|games gratuitos|game|jogos de meninos|jogos divertidos|vencerem|animacao|animando|3d|animadas|games populares|games de enigma|pontuacao|misterioso|ganhar|praticidade|webgames|torneios|jogos para pc|download de jogos|level up|jogando|games de raciocinio|controles|games de rpg|jogos legais|vantagem|jogos educativos|jogos de futebol|jogos infantis|jogos em flash|jogos de baixar|web games|games virtuais|premiando|rpg|ganhando|games de meninos|games|desenhos|jogos da hora|desafiadora|arqueiros|vencedores|brincando|freeware|games em 3d|video game|games femininos|blogueiro|animador|jogos online|games de graca|gratuitamente|jogador|competicoes|download de games|diversao|perfect world|games de computador|misterios|gratis|blogueira|usuarios|misteriosos|animados|gta|virtual|divertidas|brincadeira|interativos|poderoso|poderosas|internauta|usuarias|colegas|misteriosas|jogos eletronicos|colega|games otimos|jogos de pc|deusas|jogos de cartas|poderosa|ganhadoras|jogos 3d|vencedora|games de futebol|games animados|brincar|baixe games|gamers|animes|competidores|ganha|jogos impressionantes|diversoes|animadoras|premio|avancada|aventura|jogadores|jogos exclusivos|estrategico|comovente|players|jogos radicais|educativos|jogos de luta|jogos de wii|campeonato|equipe|jogos de celular|games de emulador|garotada|jogos de psp|interagir|jogos de acao|blogueiros|jovens|divertir|desafios|jogos de graca|vantagens|divertidos|codigo|premiado|jogos imperdiveis|avancado|jogo gratis|game gratis|enigma|desenvolvidos|games bacanas|baixe jogos|fas de games|videogames|jogos dinamicos|desafiando|codigos|element 3d|jogos belicos|interativas|games eletronicos|games divertidos|sacerdotes|games rpg|vencedoras|jogos classicos|animacoes|games de luta|divertido|games exclusivos|jogo|fas de jogos|jogos de naves|divertir se|divertida|jogos de raciocinio|jogos de download|games masculinos|deuses|games de motos|estrategicos|jogos completos|jogos animados|jogos de computador|adversaria|blogueiras|controle|online|jogar|competidor|adrenalina|magos|jogos de estrategia|games completos|jogos femininos|jogos gratuitos|jogos emocionantes|games de download|poderosos|ganhadores|animadora|games de damas|games infantis|premiada|jogos de carro|competidoras|jogadoras|animadores|jogos em 3d|jogos de rpg|truque|jogos bacanas|adversario|governanca|corporacoes|gestoras|gestao|revista hsm|business|portal de management|sucesso empresarial|gestor|portal de gestao|gestora|comunicacao corporativa|negocios sustentaveis|ideias empresariais|mundo corporativo|gestao corporativa|hsm online|lideres de gestao|portal digital|bem informado|consultores|revista hsm management|gestores|hsm management|ferramentas de gestao|management|hsm|governanca|corporacoes|controlar|softwares|integra dados|cadastra|controles|operacao|software|portal de gestao|estoques|cadastro|operacoes|sistema de gestao|negocios sustentaveis|gerenciamento|automatiza|processos|organizar|automatize|processo|mundo corporativo|sistemas de gestao|sistematizacao|gestao corporativa|cadastrar|gerencia|otimiza|lideres de gestao|otimizacao|portal digital|integracao|revista hsm management|consumos|emissao|management|ferramentas de gestao|hsm|flexibilidade|giro de capital|gestao|controla|integrado|consumo|revista hsm|controle|business|portal de management|sucesso empresarial|gerenciar|comunicacao corporativa|organizacao|ideias empresariais|sistemas|integrar dados|hsm online|operacional|interface|automacao|sistema|bem informado|sistematizacoes|consultores|agilidade|gestores|estoque|hsm management|automatizacao|gerenciamentos|modernidades|surpreendentes|infoway|inteligentes|satisfeitos|softwares|imperdivel|tecnologia de informacao|eletronicos|programadores|inovadora|portatil|hotsite|surpreendente|tecnologos|programa|modernos|aplicativo|webs|programa de computador|laptop|satisfeitas|novidades|web sites|alta definicao|multimidia|inovadores|tecnologia de ponta|internautas|wi-fi|blogueiro|programas|tecnologo|tecnologa|otimo desempenho|desempenhos|blogueira|qualidades|tecnologias de ponta|exclusiva|multimidias|itautec|internauta|net|digital|incrivel|tecnologicas|informatizados|modernidade|hot sites|hot site|inove|confiabilidade|computador pessoal|on line|conexao|tecnologia|hotsites|notebooks|infoway note|web|websites|inovacoes|qualidade itautec|exclusivo|exclusivas|mais sofisticado|ultima geracao|informatizadas|atividades diarias|programas pc|blogueiros|provedores|moderna|mobilidade|itautecshop|alta qualidade|software|otimos desempenhos|moderno|exclusivos|lancamento|tecnologico|informatizada|uso empresarial|modernas|sensacionais|eletronico|emails|compacto|e mail|mini notebook|lancamentos|tecnologica|informatizado|programa pc|provedor|uso pessoal|podcasts|inteligente|uso profissional|design moderno|inovadoras|portateis|programas de computador|internet|eletronica|exclusividade|tela ultra wide|redes sociais|banda larga|desempenho|inovar|exclusivamente|imperdiveis|lap tops|inovando|blog|blogueiras|programador|online|blogs|inovacao|wireless|via email|incriveis|exclusividades|digitais|novidade|tecnologias|alta tecnologia|aplicativos|lap top|conexoes|eletronicas|inovador|satisfeito|website|laptops|mais eficiente|mais moderno|qualidade|sensacional|ampliar horizontes|satisfeita|notebook leve|excelentes|notebook|excelente|tela wide|alta performance|web site|desenvolvedores|uso corporativo|desenvolvedor|tecnologicos|toners|economizar tempo|cor|toner de qualidade|tintas coloridas|copias coloridas|cartucho da hp|tintas|ciano|micro empresas|toner colorido|cartucho hp|material de informatica|economizar papel|menor custo|cartucho de tinta|fotocopiadora|recarga de cartuchos|toner da hp|toner original|economizar tinta|recarga de toners|copiadora|maquinas de xerox|menos custos|papelaria|xerox|empresas|material de escritorio|cartucho original|toner de tinta|cartucho preto|graficas|impressoes coloridas|originalidade|escritorios|economizar dinheiro|recarregar toners|microempresas|impressoes|cores|hp toner|sustentabilidade|recarregar cartuchos|fotocopias|toner|menor preco|homeoffice|cartucho colorido|cartucho de qualidade|tinta colorida|toner hp|cartucho|empresas pequenas|menos gastos|profissionais liberais|preto fotografico|economizar energia|magenta|xerografia|impressao|cartuchos|office jet pro|jato de tinta|tinta|toner preto|modernidades|surpreendentes|inteligentes|satisfeitos|imperdivel|tecnologia de informacao|eletronicos|criar automoveis|inovadora|surpreendente|tecnologos|modernos|designers|satisfeitas|novidades|alta definicao|multimidia|inovadores|tecnologia de ponta|fiat concept|projeto moderno|ideias|tecnologo|creative commons|tecnologa|otimo desempenho|desempenhos|qualidades|tecnologias de ponta|ideias inovadoras|exclusiva|multimidias|fiat|estilo de vida|ideias do futuro|digital|incrivel|projeto fiat|tecnologicas|ideias livres|ideias de carros|projeto criativo|desenho de carros|projeto diferente|modernidade|informatizados|inove|ideias criativas|confiabilidade|tecnologia|projeto|criar veiculos|inovacoes|exclusivas|exclusivo|sugestoes|mais sofisticado|carro conceito|opinioes|ultima geracao|carro do futuro|desenhar veiculos|informatizadas|automovel do futuro|novos projetos|moderna|criar carros|alta qualidade|ideias diferentes|otimos desempenhos|futuro|moderno|exclusivos|desenhar carros|novas ideias|modo de vida|lancamento|tecnologico|informatizada|modernas|sensacionais|eletronico|lancamentos|tecnologica|informatizado|inteligente|projeto do futuro|projeto diferenciado|inovadoras|novo desafio|making of fiat|eletronica|exclusividade|fiat mio|desempenho|inovar|projeto da fiat|exclusivamente|imperdiveis|inovando|veiculo do futuro|inovacao|making of|exclusividades|incriveis|digitais|novidade|projeto inovador|tecnologias|alta tecnologia|engenheiros|criatividade|eletronicas|fcciii|criacao de carros|novo projeto|inovador|satisfeito|engenheiros da fiat|mais eficiente|mais moderno|qualidade|sensacional|satisfeita|excelentes|ideias modernas|excelente|desenhar automoveis|alta performance|tecnologicos|softwares|tecnologia de informacao|diretor|negocio|controles|salvar|tecnologos|estoques|socio|operacoes|consultoria|placa|ddr2|gerenciamento|processos|automatiza|processo|automatize|sistematizacao|contabil|gerencia|otimiza|dados|empresas|cliente|memory cards|tecnologo|cartao de memoria|salva|consumos|emissao|informaticas|diretores|flexibilidade|drivers|nova tecnologia|giro de capital|hardware|consumo|empreendedores|administrador|microempresarios|tecnologicas|empresariais|hardwares|informatizados|sistemas|integrar dados|empresarial|automacao|sistema|sistematizacoes|empresarias|circuito|microempresarias|tecnologia da informacao|estoque|solucoes em ti|sistema informatizado|automatizacao|gerenciamentos|sistemas informatizados|micro empresarias|controlar|administradora|integra dados|cadastra|informatizadas|consultor|dl 380|empresarios|novas tecnologias|memory card|ti|operacao|micro empresario|memoria ddr|cartoes de memoria|software|consultorias|cadastro|sistema de gestao|tecnologico|organizar|informatizada|solucoes tecnologicas|socios|sistemas de gestao|cadastrar|diretoras|tecnologica|otimizacao|informatizado|clientes|integracao|comercio|assessoria|diretora|administradoras|gestao|empreendedora|controla|integrado|informatica|empreendedoras|dl 360|servidores|controle|informatico|placas|ddr|informaticos|gerenciar|empresario|empresaria|assessorias|administradores|empreendedor|organizacao|hp dl580|operacional|interface|negocios|comercios|salvando|circuitos|memorycard|ram|agilidade|empresa|diretoria|solucoes de tecnologia|tecnologicos|toners|softwares|diretor|negocio|controles|salvar|multifuncionais|estoques|socio|operacoes|consultoria|placa|laptop|hp 6000|ddr2|gerenciamento|processos|multifuncional|automatiza|monitores|processo|automatize|sistematizacao|notebook hp|contabil|roteadores|gerencia|otimiza|dados|empresas|hp 8000|webcam|cliente|memory cards|consumos|cartao de memoria|salva|emissao|diretores|flexibilidade|drivers|giro de capital|hardware|consumo|empreendedores|administrador|microempresarios|empresariais|hardwares|teclado|sistemas|integrar dados|roteador|web cans|notebooks|empresarial|automacao|sistema|sistematizacoes|empresarias|circuito|microempresarias|cartuchos|teclados|estoque|automatizacao|gerenciamentos|micro empresarias|controlar|administradora|integra dados|cadastra|consultor|web cam|empresarios|memory card|operacao|micro empresario|memoria ddr|cartoes de memoria|software|consultorias|cadastro|sistema de gestao|scanner|organizar|computadores|monitor|socios|sistemas de gestao|cadastrar|diretoras|impressora|scanners|otimizacao|clientes|integracao|comercio|assessoria|webcans|diretora|administradoras|gestao|controla|empreendedora|mouse|integrado|informatica|empreendedoras|controle|pen drives|placas|ddr|netbook|gerenciar|empresario|empresaria|assessorias|toner|administradores|empreendedor|organizacao|hp 3000|cartucho|laptops|mouses|operacional|pen drive|interface|negocios|comercios|salvando|impressoras|circuitos|notebook|memorycard|ram|netbooks|agilidade|empresa|computador|diretoria|tecnologia de informacao|diretor|negocio|salvar|tecnologos|socio|consultoria|placa|ddr2|hp laserjet 4350dtn|contabil|laser jet 2820|dados|modulos de acabamento|empresas|hp officejet j3680|cliente|memory cards|tecnologo|cartao de memoria|salva|informaticas|diretores|drivers|nova tecnologia|hardware|empreendedores|administrador|microempresarios|tecnologicas|hp laserjet 9050dn|empresariais|hardwares|hp laserjet color|informatizados|empresarial|hp laserjet p4515n|empresarias|circuito|microempresarias|tecnologia da informacao|solucoes em ti|sistema informatizado|sistemas informatizados|micro empresarias|administradora|duplexes|informatizadas|consultor|hp officejet 7680|empresarios|novas tecnologias|memory card|ti|jetdirect|micro empresario|memoria ddr|cartoes de memoria|consultorias|tecnologico|hp laserjet color 3600|informatizada|solucoes tecnologicas|socios|diretoras|hp digital sender 9250c|tecnologica|informatizado|clientes|comercio|assessoria|diretora|administradoras|hp designjet t1120ps|empreendedora|informatica|empreendedoras|informatico|placas|ddr|informaticos|gerenciar|empresario|empresaria|assessorias|administradores|empreendedor|bandejas|hp inkjet 2200|negocios|hp designjet t610|comercios|salvando|circuitos|memorycard|ram|hp laserjet p2055dn|empresa|diretoria|solucoes de tecnologia|tecnologicos|softwares|programas pc|virtualizacao de storage|programadores|programa|aplicativo|software|servidores virtuais|programa de computador|melhor capacidade|gerenciamento|grid storage|processador intel|solucoes tecnologicas|pequenas empresas|programa pc|replicacao remota|san|programas|programas de computador|rede|resultados|gerenciamento de dados|raid|hp|network raid|servidores|storage area network|escalabilidade|programador|iscsi|mais espaco|melhor desempenho|servidor hp|snapshots|aplicativos|networking|armazenar dados|virtualizacao|replicacao local|faca acontecer|cluster de armazenamento|hp storage|thin provisioning|servicos|desenvolvedores|maior eficiencia|para empresas|armazenamento|desenvolvedor|storage|nitido|nitidos|multifuncionais|laser colorida|originais hp|papeis|laser mono|lasercolor|lasejet|gastando menos|paginas|multifuncional|deskjet|confianca|mais economia|impressora|copiadora|otimo|baixo custo|distribuidores|copiadoras|alto rendimento|imprime|imprima|hp|laserjet|toners hp|melhor opcao|confiaveis|aproveitamento|reduz|gasta menos|imprimir|imprimindo|original hp|resultado|matriciais|confiabilidade|gastar menos|originais|preferencia|toner hp|nitidez|gaste menos|reducao|menos custo|otimos|rentaveis|cartuchos padrao|laser jet|impressoras|confiavel|laser color|original|matricial|distribuidora|eficiencia|baixos custos|rentabilidade|menos energia|poupar|multifuncionais hp|economizat toners|diminuir gastos|lucrar|poupar mais|rentabilidades|beneficios|lucre|reduzir custos|hp multifuncionais|menos papel|mais economia|economizar|menos custos|menos toners|xerox|baixo custo|empresas|versatilidade|reduzindo custos|diminuindo gastos|lucro|reduzindo gastos|beneficiadas|copiar|graficas|beneficiados|digitalizar|economizar dinheiro|diminuir custos|reduza gastos|investimento empresarial|lucros|sustentabilidade|menos gastos|gaste menos|reduz custos|economize|hp paysback|economizar energia|reduzir gatos|sua empresa|copiadoras laserjet|diminuindo custos|gerenciabilidade|reduza custos|beneficiada|seu negocio|empresarios|economizando|menos manutencao|solucao organizacional|poupar dinheiro|gastando menos|comprar|micro empresas|economizar papel|fax|reduz gastos|mais economico|mais beneficio|economia|economica|diminua custos|mais economica|hp impressoras|investimento|beneficiado|investimento da empresa|economico|hp laserjet|economizar mais|hp|solucao empresarial|laserjet|solucao corporativa|diminua gastos|hp copiadoras|compre|imprimir|mais lucros|beneficio|gastar menos|menos suprimentos|lucratividade|a laser|economicos|impressoras laserjet|poupar tempo|negocios|enviar fax|menos desperdicio|menos problemas|receber fax|economicas|medica|promen|psicologica|bem estar|surpreendente|vantagens|medicina|vantagem|eficiente|medicacao|remedio|psicologicas|medicas|interesse|prevencao|exames|farmaceuticos|farmaceutica|exames medicos|prevencoes|habito saudavel|prevenir|medicos|consulta|otimo|farmaceutico|avaliacao medica|exame|ministerio da saude|especialistas|menstruacao|diagnostico|cirurgias|cirurgia|flexibilidade|habitos saudaveis|aproveite|conquistas|atencao|credibilidade|psicologicos|especialista|compromissos|privacidade|farmacia|dica|satisfacao|expectativa|consultas|informacao|exame medico|farmaceuticas|remedios|ideal|necessario|qualidade|medicamentos|psicologico|convenio medico|orientacao medica|exclusivo|excelente|medicamento|medico|farmacias|interessado|despesa|consumidor|softwares|diretor|negocio|lojas|controles|gestor|vantagem|socio|estoques|agencias bancarias|consumidora|operacoes|consultoria|agencias do banco|gerenciamento|processos|automatiza|emissao de nota|compra|processo|automatize|vendedora|investidoras|sistematizacao|contabil|economizar|vender|gerencia|comercializacoes|otimiza|empresas|consumidoras|versatilidade|loja|cliente|cartoes do banco|cartoes bancarios|consumos|dinheiros|cartoes de credito|agencia do banco|debitos|consumidores|emissao|cartao de debito|cartao bancario|creditos|diretores|flexibilidade|giro de capital|comerciais|gestoras|credito|consumo|empreendedores|administrador|microempresarios|empresariais|bematech|money|economias|centros comercias|compradora|sistemas|comerciante|debito automatico|integrar dados|vendedoras|empresarial|economize|compradores|dinheiro|debito|automacao|sistema|creditos pessoais|sistematizacoes|empresarias|microempresarias|credito pessoal|estoque|varejista|automatizacao|gerenciamentos|consumir|gastos|micro empresarias|controlar|administradora|integra dados|cadastra|consultor|empresarios|vantagens|operacao|micro empresario|economizando|software|consultorias|cadastro|gestora|comercial|sistema de gestao|compras|equipamentos|comprar|micro empresas|organizar|investidor|socios|debitos automaticos|sistemas de gestao|lojistas|economia|investidores|cadastrar|diretoras|microempresa|otimizacao|clientes|integracao|cartoes de debito|comercio|assessoria|investidora|agencia bancaria|varejos|diretora|administradoras|gestao|empreendedora|controla|integrado|varejistas|vendedor|empreendedoras|microempresas|comercializacao|controle|comprando|empresario|gerenciar|vendas|empresaria|assessorias|administradores|empreendedor|organizacao|cartao do banco|vendedores|varejo|operacional|interface|negocios|lojista|comercios|centro comercial|versatil|cartao de credito|comerciantes|comprador|agilidade|despesas|venda|empresa|gestores|diretoria|micro empresa";
hwPal.hotwords3 = "redes sociais|entretenimento|hehehe|interagir|votar|verdade absoluta|postando|blogueiros|leitores|wordpress|cyber|blog|rsrs|blogs|premiar|finalista|incentivo|publico|eleitos|lol|acessar o site|hahahah|hihihi|primeiro lugar|faca sua inscricao|competicao|vencedores|premio|internautas|inscricoes abertas|certificado|blogueiro|querido leitor|postei|grande oportunidade|interatividade|reconhecimento|cadastrado|internet|postar|votem|seu blog|internautas brasileiros|mario alberto|mau humor|blogueiras|visitar o site|sustentavel|participar|sustentabilidade|ueba|postar no blog|scooter|geek|mais votado|indicacao|grande premio|participacao|de que jeito|blogues|blogosfera|mais votados|blogspot|vinicius costa|blogger|podcasts|boo|internet brasileira|juca kfouri|branding|entretenimento digital|blogueira|jakob nielsen|otimo blog|eventos|autonoma|comix|telefonando|trabalhadora|datashow|emprestimo|autonomo|jogos de motos|salvando documento|games dinamicos|condicionador de ar|comediante|conselhos|jogos masculinos|desafiador|numerico|graduados|jogos de aventura|idioma|internautas|autores|homepage|emulador|videoconferencia|telemarketing|debitos|jogos populares|comedia|morar|lucrativo|estagiando|servidores publicos|net|negociado|formandos|emprego|mouse serial|games radicais|filmado|aprendizagens|desafiadoras|manga|games de corrida|condicionar ar|lucrativa|games de estrategia|lingua inglesa|filmada|monografias|hotsites|novela|excel|magicas|servidor|vaga|games de naves|ver jogo|games educativos|processo seletivo|verao|3ds max|surpreenda|empregadas|mini system|consultor|memory card|alarmes|premiadas|aparelho telefonico|estrategia|otimismos|negociar|competidora|administrar|plateias|comercial|emuladores|micro computador|autoras|karaoke|computadores|solucoes tecnologicas|competir|fas|entrevistados|segurancas|baixar games|arquivos|humorista|comercio|anima|bacharel|curriculum|spam|anime|ensinar|plateia|conquistar|jogo on line|credibilidade|hacker|lucrando|palms|business|publicar|sugestao|wireless|desafiadores|trainee|magica|mouses opticos|remunerados|games emocionantes|cartucho|equipes|profissional|megapixel|layer|power point|games gratuitos|palmtop|marca|canal pago|academicas|garantia|jogos divertidos|ram|java|alegrias|anuncio|espetaculo|consultoras|layers|apartamento|entrevistadas|processador|socias|placas mae|tecnologos|passaportes|slogan|vantagem|remuneradas|aprimorar|full hd|jogos de baixar|necessidades|web games|bom humor|games de meninos|espanhol|desenhos|lato senso|estagios|dominios|fones|placa mae|jogos online|competicoes|download de games|gerentes|filters|corel draw|sistema operacional|televisao|blindado|bem humorados|fantasticos|colega|jogos eletronicos|cores|corel|brincar|trabalhar|gerente|pendrives|gamers|pendriver|creditos consignados|aerea|marketing|divulgacao|premio|ensinos|aventura|economize|websites|matricula|docinhos|diploma|remuneracao|impressao|call center|festivais|aereo|franquia|assistir tv|doutorados|executivos|refrigeracao|jovens|empresarios|oportunidade|conselho|cameras digitais|enigma|remunerada|efeitos graficos|ringtone|videogames|codigos|scanner|canais a cabo|franqueados|seu site|rendimentos|delphi|assinar tv|blindagem|games rpg|e mail|mini notebook|negociada|provedor|podcasts|clientes|console|jogo|playback|games masculinos|informatica|estrategicos|inovar|festejar|servidores|devedora|vantajosas|jogar|informatico|administrativas|logomarca|alta tecnologia|especializadas|artistas|frances|ensinamento|gestao estrategica|fotos|call-center|animadora|reuniao|espetaculos|educacao|pre pago|realizacao|necessario|marcas|jogos em 3d|calor|logotipo|consultores|aeroporto|agilidades|necessaria|inteligentes|comemoracoes|amigo|recuperar dados|mercado|documentos|gravadores|eletronicos|apartamentos|programadores|gestor|desenho|melhores|poupancas|hdtv|cursinho|estereo|exames|banners|monitores|creditos bancarios|jogos de emulador|computacional|curiosa|espetacular|amiga|cineminha|estrada|memory cards|agencias|financas familiares|mousepad|consumidores|fliperama|dvd player|desenvolvidas|celular|personagem|objetivo|famosas|games de aventura|empreendedores|ensinando|curioso|entender|polifonicos|tecnologia|brilhante|competicao|lingua portuguesa|documento|inovacoes|televisao lcd|dinheiro|telespectadoras|executivas|midia|bluetooth|jogos de rpg on line|remunerado|sinal digital|trilingues|jovem|eficiencia|tableless|sistemas informatizados|javac|trabalhando|tecnologas|praticas|destacar|famoso|residenciais|videogame|escritor|projetor-multimidia|empregado|jogos de corrida|micros|cartoes de memoria|famosa|cantando|melhorar|imagens digitais|mini dv|televisores|imobiliaria|filmes|jogabilidades|credibilidades|imobiliario|desenvolvido|monitorar|games de meninas|rua|jogos otimos|publicos|ganhador|desenvolvida|webcans|case|franquias|jogos free|empregada|ensinaram|mouse|empreendedoras|grandes ideias|games da hora|jogos de rpg online|administrativo|faz um emprestimo|fantastico|exercicios|addslashes|empregador|empregados|empresario|aeronaves|empresaria|imobiliarios|problemas financeiros|fantastica|negociados|lap top|conexoes|administrativa|ganhadora|tinta colorida|fotograficas|assistindo|plasma|domicilio|fluentes|preto fotografico|negocios|comercios|universitarios|sons|empresas aereas|necessarios|compradoras|telespectadores|canal fechado|toners|tela de plasma|touchpad|carteira de trabalho|fotograficos|draw|galeras|jogos educativos|socio|games virtuais|fantasticas|bem humoradas|orcamentos|universitarias|autor|socia|jogos da hora|entrevistada|praticos|jogador|fascinantes|vantajosos|cultura|games de computador|faculdades|entrevistado|tv a cabo|creditos|propaganda|financeiro|filmar|tecnologias de ponta|aparelhos de karaoke|valorizacao|aparelho de som|financeira|didatica|micro system|captura de video|humorismo|didatico|competidores|empresarial|compradores|eficaz|ringtones|operadora|jogos exclusivos|curriculum vitae|empresarias|telefone|teclados|instituicoes de ensino|comemorar|moeda|ultima geracao|consulados|grande ideia|moderna|monofonicos|tintas coloridas|esposo|televisoes|concurso|desenvolvidos|games bacanas|mp2 player|moderno|remuneracoes|linhas aereas|especializados|informatizada|games eletronicos|games divertidos|camera web|emails|informatizado|animacoes|jogos classicos|fotografadas|brilhantes|chefe|contact center|moedas|micro cameras|administra|gestao|virus|placas de som|estagiario|dvds|corrida|blog|controle|confiabilidades|pc portatil|habilidades|talentoso|orcamento|valorizacoes|beneficio|ilustradores|estagiaria|talentosa|faz emprestimo|entrevista|lucratividade|mais eficiente|novelas|scaners|competidoras|aprender|distribui o ar|sensacional|promocao|discente|salvando|caixa acustica|web site|logomarcas|esposa|fundamental|tecnologicos|digitacao|liderancas|datilografia|residencial|j2se|audiencias|headsets|surpreendente|interativa|dominio|residencias|ensina|idiomas|home theaters|aventuras|graduado|brincadeiras|interativo|dividendos|graduada|escritores|hd externo|economizar|cosplayers|desenhado|numero|webcam|tecnologo|tecnologa|exercicio|melhor|comerciais|contratada|midias|estude|jogos de damas|poupanca|linhas de financiamentos|infra vermelho|aparelho de karaoke|matematica|estudo|tecnico|contratado|editais|contabilidade|filma|ineditos|formacao cientifica|conexao|colegio|transacoes|ensino|filme|cantores|funcionarias|tv paga|sucesso|web|negociadas|escola|games legais|imobiliarias|especiais|entendimentos|intercambios|cartuchos|cancoes|endereco|sugestoes|doutorado|jogos rpg|passaporte|games engracados|professores|auditor|games impressionantes|chines|consultorias|lucratividades|heroi|premiacao|adolescencia|torneio|megapixels|noticias|autora|faturamentos|executivo|ruas|procurar emprego|mega pixels|executiva|exclusividade|teclar|disciplina|aprimore|teclas|financeiras|mouse optico|inovando|residencia|ferias|informaticos|games gratis|aplicativos|eletronicas|hds externo|trackball|localizadores|transporte aereo|htmls|novissima|satisfeito|call-centers|carreira|audio|registrar|financiando|celebridades|capital de giro|educacionais|transmissao digital|satisfeita|recrutamento|alta performance|servicos|tela lcd|desenvolvedores|computador|jato de tinta|novissimo|modernidades|pre-fabricado|download de jogos|jogando|analista de sistema|educacional|dicas|programa|pre-fabricada|fluente|jogos legais|assista|premiando|linhas de emprestimos|flash movie|empreendedorismo|aposentados|vestibulandos|som|brincando|vencedores|office xp|gerencia|dados|blogueiro|empresas|3d max|programas|surpreender|salva|blogueira|informaticas|usuarios|filmagens|palm top|multimidias|interativos|entrevistando|calcular|comediantes|games de futebol|vetorizacao|computacionais|aperfeicoar|animes|filmando|interesses|servidores estaduais|consulado|tecnologia da informacao|strpos|campeonato|equipe|gerenciamentos|design|faturar|campi|microcomputador|digitalizadores|jogos de acao|blogueiros|placa de som|hdmi|alta qualidade|contador|lucrativas|premiado|ingles|otimos desempenhos|lecionar|compras|comprar|profissionais|televisor lcd|ligar|musicas|credito empresarial|contratados|linhas de credito|fofocas|anunciando|curriculo|melhores juros|espetaculares|aulas|vencedoras|emprestimos empresariais|fas de jogos|corporativos|escritoras|experiencia|camera fotografica|jogos de raciocinio|funcionarios|famosos|games de motos|faca um emprestimo|localizador|filho|docinho|fotografos|online|emprestimos|via email|passatempos|digitalizando|driver|filha|j2me|premiada|sms|scanear|ouvir musica|jogos bacanas|candidatos|plano de vantagens|vantajosa|vestibular|desenhistas|diretor|pensionistas|vantajoso|mega pixel|eficiente|festas|divulgar|consumidora|rendimento|arte|consultoria|pagamento|novissimos|assalariada|pontuacoes|inovadores|confortaveis|enderecos|premios|emocao|empregos|interessantes|pessoas juridicas|faculdade|games de carro|apostilas|leciona|digitar|digital|headphone|assalariado|recuperar arquivos|festival|hot sites|poliglotas|handheld|antispyware|jogos de xbox|headphones|conforto|debito|atendimentos|familias|episodio|terreno|licenciatura|estudiosa|candidato|teleconferencia|felizes|programacao|games online|publicitario|ensino a distancia|estudioso|disputa|jsp|construtora|aposentadas|festa|conhecimentos|jogos engracados|fotografia|sensacionais|publicitaria|pctv|oportunidades|anunciar|telespectador|servico telefonico|page maker|branding|financeiros|portateis|impressionantes|concursadas|assistir|condominio|devedores|amigos|games de guerra|vestibulanda|academicos|talentosas|aluno|profissionais de ti|netbook|backups|jogos de terror|vestibulando|aluna|empreendimento|htms|divertir-se|alunos|mangas|interessados|3g|microsystem|notebook|servico|3d|agilidade|gestores|html|torneios|cursos|jogos para pc|propagandas|portatil|merchandising|sobremesas|visual basic|jogos infantis|apresentar|interesse|lucre|registra|aproveitar|mobilidades|funcionario|eficazes|video game|registre|dia quente|seguro|otimo desempenho|contratadas|lucro|calculos|funcionaria|diretores|qualidades|datilografar|interessadas|parceira|micro computadores|estudantes|home-theaters|instituto educacional|celebridade|internauta|usuarias|criar|colegas|fins de semana|tcc|aprendizado|games otimos|cargo|anti virus|renda|devedoras|cpus|ganhadoras|aprendendo|velocity|vocacional|hot site|fotografar|games animados|televisor|campanhas|fotografas|formatar hds|baixe games|palestras|apresentacao|smartphones|malwares|animadoras|quadrinho|curiosidade|jogadores|acao|linha de credito|curriculos|phyton|jogos radicais|jogos de luta|trabalhos|linha de financiamento|capitais de giro|diplomas|talentosos|sofisticada|garotada|projetor|jogos de psp|cursos de extensao|estagiar|plano imperdivel|didaticas|vml|codigo|ilustradora|ineditas|indispensaveis|calculo|produtividades|sofisticado|fas de games|projetos|teve digital|anunciante|interativas|contadora|inteligente|taxi aereo|inovadoras|assistir jogos|word|destaque|campus|emprestimo empresarial|educativas|por assinatura|imovel|imperdiveis|pagamentos|chefes|inovacao|jogos de estrategia|games completos|universitario|dica|voo|enem|feliz|ganhadores|exibicoes|universitaria|games de damas|website|recem formado|jogadoras|linux|animadores|adolescentes|estudantis|formatura|cinema|divulgando|intercambio|estudantil|melhores taxas|desktop|apostila|emocionante|analistas de sistema|moradia|aplicativo|musica|conectados|desafio|publicidade|carreiras|substr|alarme|web design|ensinamentos|aula|esposas|cobertura nacional|cliente|dinheiros|ensino superior|servicos telefonicos|3d studio|digitalizar|voar|recem-formados|atencao|tela|games de humor|empresariais|turmas|cobol|projetores multimidia|engracados|construtoras|antifurto|jogos de meninas|circuito|exclusivas|informar|bem sucedidas|credito pessoal|jogue|jogabilidade|placas de video|jogos|games de baixar|informatizadas|anuncios|lcd|conectada|armazenar|financeiramente|lares|adversarias|scaner|interatividades|audios|software|novissimas|pcs|pda|games de cartas|conectado|bixete|ciano|monitor|servidor federal|pessoas fisicas|conquista|artes|curiosas|economica|desenhados|pensionista|numerais|assine tv|consoles|informacoes|consignado|mousse|recem-formado|pos-pago|curiosidades|disputas|economico|matematicas|objetivos|brinca|auricular|administracao|mouses seriais|consolas|impressoes|misterio|ddr|jogos on line|estagio|gravador|polegadas|celulares|lar|estudando|empreendedor|sites|vencendo|hds|passageiros|empregadores|rentaveis|antivirus|vencerem|estagiarias|ligacoes|financiamentos|animando|memorycard|empresa|negociacao|assista jogo|logotipos|praticidade|contabilidades|fotografo|imperdivel|fotografe|salvar|mestrados|flash mx|modernos|bom gosto|fotografa|cante|php|torpedo|importante|atendimento|multimidia|alta definicao|desafiadora|games femininos|calculadoras|recurso financeiro|games de graca|comunicacao|atrizes|pessoa fisica|css|calculadora|divertidas|virtual|otimismo|trainees|brincadeira|armazenamentos|misteriosas|projetores|publicitarias|vestibulares|jogos de cartas|filmadora digital|inedito|videoconferencias|jogos 3d|economias|resolucao|ver jogos|eficiencias|astros|entretenimentos|inedita|eficientes|palestrante|otimos|financa|educativos|edital|mouse pad|hard disk|assistir jogo|aprendizados|novas tecnologias|divertir|jogos de graca|vantagens|recursos financeiros|emprestimo pessoal|cantar|condicionadores de ar|jogos dinamicos|comemoracao|especial|convidada|pratico|bixo|escanear|scanners|habitacionais|games de luta|convidado|vetor|palestra|convidados|varredura|jogos de naves|pacote office|produtividade|headset|exclusivamente|humoristas|jogos de computador|hospedagem|negociando|pratica|agencia|tv aberta|oferta|alunas|concursados|colegios|lazeres|transportes aereos|seriados|desenhista|vida profissional|criacao|webwork|marketeira|excelente|franqueado|telas|marketeiro|empreendedorismos|computador de mao|rentabilidade|j2ee|campeao|dicas de jogos|estudante|negocio|fofoca|economistas|webs|dias quentes|palestrantes|conversor|actionscript|ddr2|mercado de trabalho|alegres|games surpreendentes|cosplay|clt|exito|tecnologia de ponta|dicas de games|passagem aerea|games imperdiveis|rendas|office 2007|operadoras|trilingue|professor|projetos educativos|desempenhos|telecomunicacoes|criacoes|conectadas|assinar canal|assine|sem dinheiro|usb|incrivel|servidores federais|enigmas|informatizados|video games|ensino universitario|new symbol|on line|jogos de guerra|site|games de acao|adversarios|divida|designer|confortavel|notebooks|lingua espanhola|interatividade|financas empresariais|convencional|games classicos|games de pc|publicidades|vetores|divulgador|jogos surpreendentes|games de esporte|cor|herois|home-theater|playbacks|microcomputadores|recem formados|autonomas|karaokes|telespectadora|microfone|placa de rede|gps|voos|projetor multimidia|emprestimos pessoais|lancamento|vencedor|aprimoramento|lingua francesa|estagiarios|estrategias|episodios|economia|cpu|eletronico|programa pc|tutoriais flash|salario|tv de plasma|promocoes|eletronica|habitacao|alegria|acoes|jogos incriveis|misteriosa|esposos|blogs|fim de semana|passatempo|didaticos|micro|tv lcd|adobe golive|corretora|digitaliza|concursado|digitalize|tv digital|games belicos|camera|mouses|assalariadas|telefonicos|empreender|jogos de meninos|bilingue|negocia|placa-mae|lucrativos|animacao|sabedoria|retroprojetor|misterioso|docente|concursada|economicas|trabalhador|despesa|canal a cabo|salarios|faturamento|instituicao de ensino|amigas|comedias|jogos de futebol|laptop|satisfeitas|ganhando|games|compra|financiados|cds|corretoras|turma|concurso publico|tecla|misterios|gta|misteriosos|drivers|nova tecnologia|assalariados|culturas|produtos|desktops|foto digital|moradores|teclado|compradora|fotografando|inscricao|cases|estudiosos|comunicar|remunerar|maquina fotografica|folder|concursos|creditos pessoais|fliperamas|astro|curso|led|estrategico|companhia aerea|solucoes em ti|sofisticados|tinta|tv fechada|interagir|servidor estadual|desafios|jogos imperdiveis|cgi|blu-ray|mp4 player|exclusivos|jogos belicos|digite|telefonema|home theater|lecionando|financie|aperfeicoe|maquinas digitais|congressos|corretores|aperfeicoa|assitir a copa|escaner|seriado|jogos de download|redes sociais|empreendedora|pos pago|aereos|jogos animados|jogos completos|sobremesa|blogueiras|programador|pen drives|adrenalina|compre|nivel medio|corretor|jogos gratuitos|toner|terrenos|games de download|arquivo|cameras|games infantis|laptops|biblioteca|discentes|corporativo|ilustracao|pen drive|netbeans|cantor|macromedia flash|sem burocracia|nivel superior|tutorial html|slogans|entretenimento|fones de ouvido|docentes|tecnologia de informacao|jogos de humor|truques|blindados|emprestimo consignado|personagens|banco de dados|filmadora|imoveis|publico|novidades|games on line|passagens aereas|vencer|portfolio|hosting|hd|animada|campanhas publicitarias|autonomos|animado|exclusiva|tvs digitais|games free|desafiar|emprestimo bancario|lideranca|jogos de playstation|fone de ouvido|confiabilidade|graduacao|ilustracoes|movie clip|protecao|fa|ideia|fatura|exclusivo|jogos de esporte|facilidade|lazer|assista a copa|campeonatos|desafiante|avancadas|player|portabilidade|portabilidades|especializada|tecnologia 3g|importantes|aprendizagem|contratar|comunicador|futuro|sistema gps|maquinas fotograficas|tv de led|polifonico|campanha|protegido|multitarefas|destaques|financiar|computadores de mao|webmarketing|consultora|infravermelho|disciplinas|regravavel|profissional de ti|especializado|placas de rede|divulgacoes|financiamento|bonus|voando|processadores|internet|telefonias|jogos gratis|cd|mobile|telefonico|recurso humano|reunioes|usuario|credito consignado|monitoramento|imagens|usuaria|mestrado|habitacional|protegida|divirta se|exclusividades|proteger|financas|marketeiros|tv de lcd|creditos empresariais|bem sucedida|canais fechados|economicos|game|blindagens|excelentes|consignados|filhas|games de enigma|armazenamento|surpreendentes|satisfeitos|consumidor|ilustrador|cameras fotograficas|games de raciocinio|hotsite|controles|virtuais|programa de computador|fotografico|jogos em flash|fill color|lucrar|gerenciamento|vetorizar|games em 3d|otimo|trabalho|animador|docerias|ideias|diversao|pc|fotografados|trabalha|animados|hardware|problema financeiro|credito|poderosas|necessidades financeiras|tecnologicas|empreendimentos|fotografias|hardwares|otima|final de semana|hd interno|modernidade|inove|universidade|sofisticadas|backup|banner|financas pessoais|fotografica|dvd|ideal|fotografado|avancada|financiado|educar|cosplayer|estudar|filmagem|caixas acusticas|tela plana|dividendo|players|jogos de wii|fotografada|insert|marketeiras|games de emulador|cosplays|ator|web cam|powerbuilder|mobilidade|graduandos|avancado|economista|contadoras|familia|pecl|comunicadores|desafiando|tecnologico|ides|negociacoes|talento|telecomunicacao|lancamentos|sucessos|tecnologica|spyware|pessoa juridica|academica|estudiosas|entendimento|divertir se|sistemas operacionais|artista|hq|academico|trojans|adversaria|webdesign|divulgadores|comprando|placas|incriveis|tecnologias|interessante|jogos femininos|telecom|javascript|inovador|jogos de carro|mais moderno|necessidade|pagar|truque|atores|netbooks|despesas|adversario|emprestimos bancarios|necessarias|indispensavel|widescreen|desenvolvedor|passagens|numeral|softwares|curiosos|telefonemas|passagem|instituicao|projetor de slides|hospedagens|devedor|confira|formatar hd|placa|anti furto|baixar jogos|habilidade|rentabilidades|beneficios|servidor publico|games em flash|contadores|bem humorado|handycam|bem humorada|windows|consumidoras|cartao de memoria|moradias|inscricoes|flexibilidade|xhtml|call centers|credito bancario|exibicao|necessidade financeira|folders|evento|interessada|perl|emocionantes|premiacoes|bilingues|projeto|divirta-se|jogos de espionagem|avancados|tv|jogos de enigma|interessado|handhelds|mais sofisticado|telefonia|escolares|instituicoes|filhos|games de espionagem|infantis|ti|comunicacoes|memoria ddr|parceiras|monografia|games de terror|htm|se divertir|plano pos|comprometimento|adolescente|audiencia|xml|ar condicionado|poliglota|premiados|palm|macromedia|dividas|nivel fundamental|fascinante|qualidade do ar|desafiantes|congresso|banda larga|aproveite|alegre|jogadora|games incriveis|rh|lap tops|mp5 player|sistemas gps|linha de emprestimo|novidade|digitais|plano pre|mp3 player|atriz|cursinhos|linha aerea|financas organizacionais|melhor plano|cine|estradas|hackers|hqs|aprimoramentos|talentos|cancao|comprador|animadas|games populares|foto|solucoes de tecnologia|pontuacao|ganhar|webgames|educativo|inovadora|quadrinhos|games de rpg|mini mouses|rentavel|televisao digital|ar fresco|vbscript|web sites|ideais|campanha publicitaria|anunciantes|seguranca|wi-fi|exame|aprenda|pre-pago|assista jogos|finais de semana|conhecimento|java script|apresentacoes|cargos|institutos educacionais|sem complicacao|produto|pcs portateis|poderoso|aparelhos telefonicos|compromissos|jogos de pc|lucros|programacoes|mini mouse|alfabetizacao|poderosa|compromisso|portfolios|money|entrevistar|vencedora|mercados|entrevistas|ligacao|informacao|impressionante|ganha|torpedos|ofertas|telefones|jogos impressionantes|diversoes|imagem digital|magenta|televisao de led|sistema informatizado|dhtml|jogos de celular|digitalizador|video-game|programas pc|provedores|bem estar|refrigeracoes|divertidos|economizando|concursos publicos|financas corporativas|object pascal|captar imagens|tintas|baixe jogos|pendrive|localizar|vagas|escolar|modernas|engracadas|jogo online|socios|escolas|fone|graduadas|convidadas|escritora|divertido|games exclusivos|imagem|educacao superior|universidades|trabalhadores|programas de computador|divertida|aparelhos de som|fazer emprestimo|morador|gravar|noticia|desempenho|hd-dvd|mp4|mp3|mp5|emprestimos consignados|competidor|armazena|fazer um emprestimo|multitarefa|numeros|gerencias|gerenciar|jogos emocionantes|poderosos|otimas|aposentada|regravaveis|estudos|firewall|faca emprestimo|mms|telefonar|qualidade|engracada|galera|cavalo de troia|camera digital|jogos de rpg|publicitarios|circuitos|educativa|transacao|placa de video|aposentado|engracado|matriculas ";
function hwClick(p){
try{
hwPal["clique" + hwPals[hwPal.smalPals(p)]]();
}catch(e){
hwPal["cliqueAnuncie"]();
}
}
function hwShow(e, obj, p){
try{
hwPal["mostratudo" + hwPals[hwPal.smalPals(p)]](e, obj, hwPals[hwPal.smalPals(p)]);
}catch(err1){
hwPal["mostratudoAnuncie"](e, obj, 0);
}
}
hwPal.codigo="$1<a href='#' onClick='hwClick(\"$2\");return false;' style='cursor: hand; color:#006600; text-decoration:underline; border-bottom:dotted 1px;' onmouseover='hwShow(event, this, \"$2\"); this.style.cursor=\"hand\"; this.style.textDecoration=\"underline\"; this.style.borderBottom=\"solid\";'  onmouseout='hideMaybe(this, \"$2\"); this.style.cursor=\"hand\"; this.style.textDecoration=\"underline\"; this.style.borderBottom=\"dotted 1px\"; ' oncontextmenu=\"return false;\">$2</a>$4";
hwPal.palll=function(h, b, z){
if (h != undefined){
if (b && z){
return hwPal.smalPals(h);
}else{
if (b){
return hwPal.inifirstSmalPals(h);
}else{
if (z){
return hwPal.fimfirstSmalPals(h);
}else{
return hwPal.firstSmalPals(h);
}
}
}
}
}
hwPal.addPals=function(h){
if (hwPals[h] == undefined){
hwPals[h] = hwPal.count;
hwPal.count = hwPal.count +1;
if (hwPal.encontrados == undefined){
hwPal.encontrados = new Array();
}
hwPal.encontrados.push(h);
}
}
hwPal.getClass=function(c,f,m){
if(c.getElementsByClassName&&Array.filter){
return Array.filter(c.getElementsByClassName(f),function(e){return m.indexOf(e.nodeName)>=0})
}else{
c=c||document;
var o,h,g=0,l=[],b,k=[],a=new RegExp("(^|\s)"+f+"(\s|$)");
for(o in m){
l=c[mc.gT](m[o]);
for(h=0,b=l.length;h<b;h++){
if(a.test(l[h][mc.cN])){k[g]=l[h];g++}
}
}
return k;
}
}
hwPal.remove = function(array, from, to) {
var rest = array.slice((to || from) + 1 || array.length);
array.length = from < 0 ? array.length + from : from;
return array.push.apply(array, rest);
};
hwPal.procura=function(m, a){
var s=m.childNodes;
for(var c=0;c<s.length;c++){
if (qtdAnuncios < maxQtdAnuncios){
var r=s[c];
if((r!=undefined)&&typeof(r["nodeType"])!=undefined){
if(r["nodeType"]==3){
var regExp=new RegExp("(^|[^a-zA-ZÁ-öù-ÿ0-9])(("+hwPal["hotwords" + a]+"))([^a-zA-ZÁ-öù-ÿ0-9]|$)","gi");
var h=r.nodeValue.match(regExp);
if(h){
var o,lk,j="";
if ((h.length+qtdAnuncios) > maxQtdAnuncios){
var we = h.length+qtdAnuncios - maxQtdAnuncios -1;
hwPal.remove(h, 0, we);
}
var gg = "";
for(o=0; o<h.length; o++){
var b = r.nodeValue.indexOf(h[o]) == 0;
var z = r.nodeValue.indexOf(h[o]) + h[o].length == r.nodeValue.length;
var resultSpChar = new RegExp("[\n\u8220\u8221\u02F5\u02F6\u0022\u02BA\u02F5\u02F6\u201C\u201D\s!,#$%&'*+<>():;\.\\/¿¡=?`{|}~^-]+");
if(resultSpChar.test(h[o][0])) {
    b = 0;
} else if(resultSpChar.test(h[o][h[o].length-1])) {
    z = 0;
}
var g = hwPal.palll(h[o], b, z);
hwPal.addPals(g);
if (o == 0){
gg = g;
}else{
gg = gg + "|" + g;
}
}
qtdAnuncios += h.length;
var reggg = new RegExp("(^|[^a-zA-ZÁ-öù-ÿ0-9])(("+gg+"))([^a-zA-ZÁ-öù-ÿ0-9]|$)","gi");
lk=d["createElement"]("taghw");
lk["innerHTML"]=r.nodeValue["replace"](reggg,hwPal.codigo);
if(reggg.global||navigator.userAgent.match("\bMSIE [456]\b")){
for(o=0;o<h.length;o++){
h[o]=h[o]["replace"](new RegExp("(^[^a-zA-ZÁ-öù-ÿ0-9]|[^a-zA-ZÁ-öù-ÿ0-9]$)","g"),"");
h[o]=h[o]["replace"](/s$/,"");
j+=h[o]+"|"
}
j=j.substr(0,j.length-1);
j=new RegExp("\\|("+j+")s?(\\|)|^("+j+")s?\\||\\|("+j+")s?$","gi")
}else{
j=new RegExp("\\|("+h[3]+")s?(\\|)|^("+h[3]+")s?\\||\\|("+h[3]+")s?$","gi")
}
if(r.nodeValue.substr(0,1)===" "){
lk["innerHTML"]="&nbsp;"+lk["innerHTML"]
}
m["replaceChild"](lk,r);
}
}else{
if (hwPal.tr < 50){
if(r["nodeType"]==1&&r["nodeName"].toLowerCase().match(/\b(div|taghw|tbody|p|b|i|u|tt|strong|em|font|span|table|tr|td|ul|ol|li|h4|h5|h6|center|quote|q|dl|dt|dd)\b/i)){
hwPal.procura(r, a);
hwPal.tr++;
}
}
}
}
}
}
};
var divis = d.getElementsByTagName("div");
for(var z=0; z < 4;z++){
if ((hwPal["hotwords" + z] != undefined) && (hwPal["hotwords" + z].length > 0)){
for(var b=0; b < divis.length;b++){
if (qtdAnuncios < 4){
hwPal.tr =0;
if (divis[b].id == "HOTWordsTxt"){
hwPal.procura(divis[b], z);
}
}
}
}
}
function showTitle(e, obj, txt, lnk, lxt) {
var xxx="<div id='HW_Container_Custom'><div id='HW_Topo'><div id='HW_Espaco_Custom'>&nbsp;</div><div id='HW_Fechar'><a alt='HOTWords' onclick=\"javascript: hideBL('HOTWordsTitle');\" ><img src='http://img.hotwords.com.br/img/transp_hotwords_2.gif' alt='' width='12' height='17' border='0' /></a></div></div><div id='HW_Conteudo' onclick=\"window.open('http://zone100.hotwords.com.br/redir2.jsp"+ lnk +"','_blank');\"><div id='HW_Texto'>"+ txt + "</div><div id='HW_Link'><p>Clique aqui e saiba mais</p></div></div><div id='HW_Logo_Custom'><a href='http://site.hotwords.com.br/?r=17518'  alt='HOTWords' target='_blank' onmouseover=\"window.status=''; return true;\"><img src='http://zone100.hotwords.com.br/img2.jsp"+ lnk +"' width='100' height='10' border='0' /></a></div></div>";
printHW(e, obj, xxx);
}
function printHW(e, obj, xxx) {
try{
 hotwordsEliminaDesaparecerXY = true; this.tek=true;
var Yposition,Xposition,Yevent,Xevent;
var xWindow = window.innerWidth;
var yWindow = window.innerHeight;
var oEvt = e || window.event;
Yevent = oEvt.clientY;
Xevent = oEvt.clientX;
if ((Xevent + 30 + 276) < xWindow){
 Xposition = Xevent - 45;
}else{
 Xposition = Xevent - 10 - 276;
}
if((Yevent - 145) < 0){
 Yposition = Yevent + 30; 
}else{
 Yposition = Yevent - 20 - 145; 
}
if (document.all) {
document.all.HOTWordsTitle.all.HOTWordsTitleText.innerHTML = xxx; 
document.all.HOTWordsTitle.style.left = Xposition;
document.all.HOTWordsTitle.style.top = Yposition; 
document.all.HOTWordsTitle.style.display = '';
document.all.HOTWordsTitle.style.zIndex = 1000000; 
document.all.HOTWordsTitle.overflow = 'visible'; 
document.all.HOTWordsTitle.style.visibility = 'visible';
} else {
var oLayer = d["getElementById"]('HOTWordsTitle');var oLayerTxt = d["getElementById"]('HOTWordsTitleText');oLayer.style.top = Yposition + "px";oLayer.style.zIndex = 1000000; oLayer.style.overflow = 'visible'; oLayer.style.left = Xposition + "px";oLayerTxt.innerHTML = xxx;oLayer.style.display = '';oLayer.style.position = 'fixed';oLayer.style.visibility = 'visible';}
}catch(e){}
}
function getScrollTop() {var s = 0;if (window.getSelection) {return document.body.scrollTop;}if (document.documentElement && document.documentElement.scrollTop) {s = document.documentElement.scrollTop;}else if (document.body && document.body.scrollTop) {s = document.body.scrollTop;}return s;}
function mouseX(evt) {
if (evt.pageX) return evt.pageX;
else if (evt.clientX)
return evt.clientX + (document.documentElement.scrollLeft ?
document.documentElement.scrollLeft :
document.body.scrollLeft);
else return null;
}
function mouseY(evt) {
if (evt.pageY) return evt.pageY;
else if (evt.clientY)
return evt.clientY + (document.documentElement.scrollTop ?
document.documentElement.scrollTop :
document.body.scrollTop);
else return null;
}
function var50(g, i, q, k, v, p, x){}function var30(t, v){}function getScrollLeft(){if (window.getSelection) {return document.body.scrollLeft;}var s = 0;if (document.documentElement && document.documentElement.scrollLeft){s = document.documentElement.scrollLeft;}else if (document.body && document.body.scrollLeft){s = document.body.scrollLeft;}return s;}function getStyle(oElm, strCssRule){ var strValue = ''; if(document.defaultView && document.defaultView.getComputedStyle){ var css = document.defaultView.getComputedStyle(oElm, null); strValue = css ? css.getPropertyValue(strCssRule) : null; } else if(oElm.currentStyle){ strCssRule = strCssRule.replace(/\\-(\\w)/g, function (strMatch, p1){ return p1.toUpperCase(); }); strValue = oElm.currentStyle[strCssRule]; } return strValue; } function Draggable(el){ 
var xDelta = 0, yDelta = 0; 
var xStart = 0, yStart = 0; 
function enddrag(){ 
document.onmouseup = null; 
document.onmousemove = null; 
} 
function drag(e) 
{ 
e = e || window.event; 
hotwordsEliminaDesaparecerXY = false; 
xDelta = xStart - parseInt(e.clientX); 
yDelta = yStart - parseInt(e.clientY); 
xStart = parseInt(e.clientX); 
yStart = parseInt(e.clientY); 
el.style.top = (parseInt(el.style.top) - yDelta) + 'px'; 
el.style.left = (parseInt(el.style.left) - xDelta) + 'px'; 
} 
function md(e){ 
e = e || window.event; 
xStart = parseInt(e.clientX); 
yStart = parseInt(e.clientY); 
el.style.top = parseInt(getStyle(el,'top')) + 'px'; 
el.style.left = parseInt(getStyle(el,'left')) + 'px'; 
document.onmouseup = enddrag; 
document.onmousemove = drag; 
return false; 
} 
el.onmousedown = md; 
} 
hwPal.mostratudoAnuncie=function(e, obj, c){
 var xxx="<div id='HW_Container_Custom'><div id='HW_Topo'><div id='HW_Espaco_Custom'>&nbsp;</div><div id='HW_Fechar'><a alt='HOTWords' onclick=\"javascript: hideBL('HOTWordsTitle');\" ><img src='http://img.hotwords.com.br/img/transp_hotwords_2.gif' alt='' width='12' height='17' border='0' /></a></div></div><div id='HW_Conteudo' onclick=\"window.open('http://site.hotwords.com.br/','_blank');\"><div id='HW_Texto'><h1>Anuncie aqui</h1><p>HOTWords.com.br lider em intext advertising</p></div><div id='HW_Link'><a onmouseover=\"window.status=''; return true\" >HOTWords.com.br</a></div></div><div id='HW_Logo_Custom'><a href='http://site.hotwords.com.br/'  alt='HOTWords' target='_blank' onmouseover=\"window.status=''; return true;\"><img src='http://img.hotwords.com.br/img/transp_hotwords_2.gif' width='100' height='10' border='0' /></a></div></div>";
printHW(e, obj, xxx);
}
hwPal.cliqueAnuncie=function(){
var newWindow = window.open('http://site.hotwords.com.br', '_blank');
newWindow.focus();
return false;
}
function printLayerHOTWords(a){
try {
var temp = document.getElementById(a);
if (temp == null){
var scriptElement = document.createElement('div');
scriptElement.id = a;
scriptElement.style.zIndex = 1000000;
scriptElement.style.cursor = 'move';
scriptElement.style.position = 'absolute';
scriptElement.style.visibility= 'hidden';
scriptElement.style.display = 'none';
scriptElement.style.width = '0';
scriptElement.style.overflow = 'visible';
scriptElement.onmouseout = function(){ hideMaybe(this.id); };
scriptElement.onmouseover = function(){ showSure(); };
var z = scriptElement.appendChild(document.createElement('div'));
z.id = a + 'Text';var head = document.getElementsByTagName('body')[0];if (head != null) {if (head.firstChild != null) {try {head.insertBefore(scriptElement, head.lastChild);}catch(e){head.appendChild(scriptElement);}}else{head.appendChild(scriptElement);}}new Draggable(document.getElementById(a));
}
}catch(e){return false; }
return true;
}
if ((hwPal.encontrados != undefined) && (hwPal.encontrados.length > 0)){
css_start();
printLayerHOTWords("HOTWordsTitle");
for(var b=0; b < hwPal.encontrados.length;b++){
try{
var p = hwPals[hwPal.encontrados[b]];
var ok = hw_exl('http://zone100.hotwords.com.br/mostraV2.js?c=49&h=mtKXntqYodi2mcmJBM8JiZq5&pl=' + p + '&id=17518&i=' + b + '&p=' + escape(hwPal.encontrados[b]) + '&d=http%3A%2F%2Fanalistasi.com.br%2F%3Fp%3D97');
}catch(e){}
}
}
scriptElement = null; 
head = null;
}catch(e){}
