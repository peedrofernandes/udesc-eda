struct dados {
  int x;
  int y;
};

struct multipilha {
  int topo1;
  int topo2;
  int tamanho;
  struct dados *vetor;
};

struct multipilha *criarMultipilha(int tam);

void destruirMultipilha(struct multipilha *m);

void reiniciarMultipilha(struct multipilha *m);

void reiniciarP1(struct multipilha *m);

void reiniciarP2(struct multipilha *m);

void inserirP1(struct multipilha *m, struct dados d);

void inserirP2(struct multipilha *m, struct dados d);

void removerP1(struct multipilha *m);

void removerP2(struct multipilha *m);

int pilhaCheia(struct multipilha *m);

int pilhaVazia(struct multipilha *m);

struct dados buscarTopoP1(struct multipilha *m);

struct dados buscarTopoP2(struct multipilha *m);

int obterQtd(struct multipilha *m);

int obterQtdP1(struct multipilha *m);

int obterQtdP2(struct multipilha *m);