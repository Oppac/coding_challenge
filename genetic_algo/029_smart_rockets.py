import math
from random import randrange
import pygame

WIDTH = 800
HEIGHT = 600
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)


class Agent():
    def __init__(self):
        self.ag_rect = pygame.rect.Rect((0, 0, 15, 15))
        self.pos = pygame.math.Vector2((WIDTH/2, HEIGHT))
        self.vel = pygame.math.Vector2(1, 0).rotate(randrange(360))
        self.acc = pygame.math.Vector2(0, 0)
        self.color = (randrange(255), randrange(255), randrange(255))

        self.completed = False
        self.crashed = False

    def update(self):
        self.vel += self.acc
        self.pos += self.vel
        self.ag_rect.center = self.pos
        self.acc *= 0

        if (self.ag_rect.right > WIDTH or self.ag_rect.left < 0 or
            self.ag_rect.top < 0 or self.ag_rect.top > HEIGHT):
            self.crashed = True

    def draw(self):
        pygame.draw.rect(SCREEN, self.color, self.ag_rect)


def new_pop(nb):
    return [Agent() for _ in range(nb)]


def main():
    pygame.display.set_caption("Smart rockets")
    clock = pygame.time.Clock()

    pop = new_pop(25)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT: return

        clock.tick(60)
        SCREEN.fill(BLACK)
        for ag in pop:
            ag.update()
            ag.draw()
        pygame.display.flip()

if __name__ == '__main__':
    main()
