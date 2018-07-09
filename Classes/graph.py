class Graph:
    def __init__(self, vertex, edges):
        self.vertex = vertex
        self.edge = edges
        self.nodes = []
        self.nodeObjects = []

    def addNode(self):
        for i in range(self.edge):
            e, v, w = map(int, input().split())
            if not (e in self.nodes):
                node = Node()
                node.value = e
                self.nodes.append(e)
                self.nodeObjects.append(node)

            if not (v in self.nodes):
                node2 = Node()
                node2.value = v
                self.nodes.append(v)
                self.nodeObjects.append(node2)
                
            if not (node in self.nodeObjects[self.nodes.index(v)].connections):
                self.nodeObjects[self.nodes.index(v)].connections.append(node)
                
            if not (node2 in self.nodeObjects[self.nodes.index(e)].connections):
                self.nodeObjects[self.nodes.index(e)].connections.append(node2)    


class Node:
    value = 0
    connections = []
    weight = []
    distance = 0
