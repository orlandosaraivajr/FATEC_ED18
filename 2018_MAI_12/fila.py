'''
 Exemplo do uso de fila.

 Prof. Me. Orlando Saraiva Jr
 Criado em : 07/05/2018
 '''


class Fila:
    """ Classe Fila, representando uma fila """
    def __init__(self):
        """No construtor, cria-se uma lista """
        self._data = []

    def __len__(self):
        """Retorna o tamanho da fila"""
        return len(self._data)

    def is_empty(self):
        """Checa se a fila está vazia"""
        return len(self._data) == 0

    def insere(self, e):
        """Adiciona um elemento a fila"""
        self._data.insert(0, e)

    def remove(self):
        """Remove um elemento da fila"""
        if self.is_empty():
            print('Fila vazia')
        else:
            return self._data.remove(self._data[-1])

    def __str__(self):
        return str(self._data)


def exercicio_1_1():
    objeto_fila = Fila()
    objeto_fila.insere(1)
    objeto_fila.insere(2)
    objeto_fila.insere(3)
    objeto_fila.remove()
    print(objeto_fila)
    print("Tamanho da fila: " + str(len(objeto_fila)))


def exercicio_1_2():
    objeto_fila = Fila()
    for x in range(1, 10):
        objeto_fila.insere(x)
    print(objeto_fila)
    print("Tamanho da fila: " + str(len(objeto_fila)))


def exercicio_1_3():
    objeto_fila = Fila()
    for x in range(1, 5):
        objeto_fila.insere(x)
        objeto_fila.insere(x)
    print(objeto_fila)
    print("Tamanho da fila: " + str(len(objeto_fila)))


def exercicio_1_4():
    objeto_fila = Fila()
    for x in range(1, 10):
        objeto_fila.insere(x)
    for x in range(1, 5):
        objeto_fila.remove()
    print(objeto_fila)
    print("Tamanho da fila: " + str(len(objeto_fila)))


def exercicio_1_5():
    objeto_fila = Fila()
    for x in range(1, 10):
        objeto_fila.insere(x)
    for x in range(1, 5):
        objeto_fila.remove()
    for x in range(1, 10):
        objeto_fila.insere(x)
    print(objeto_fila)
    print("Tamanho da fila: " + str(len(objeto_fila)))


if __name__ == '__main__':
    exercicio_1_1()
    exercicio_1_2()
    exercicio_1_3()
    exercicio_1_4()
    exercicio_1_5()
