import sys
import pygame

WIDTH = 800
HEIGHT = 600
BG_COLOR = (230, 230, 230)

class Ship:
    def __init__(self, screen):
        self.screen = screen
        self.screen_rect = self.screen.get_rect()
        self.ship_rect = pygame.rect.Rect((0, 0, 30, 60))
        self.ship_rect.midbottom = self.screen_rect.midbottom

        self.ship_speed = 1
        self.moving_right = False
        self.moving_left = False

    def update(self):
        if self.moving_right and self.ship_rect.right < self.screen_rect.right:
            self.ship_rect.x += self.ship_speed
        if self.moving_left and self.ship_rect.left > 0:
            self.ship_rect.x -= self.ship_speed

    def draw(self):
        pygame.draw.rect(self.screen, (0, 255, 0), self.ship_rect)


class Bullet():
    def __init__(self, screen, ship):
        self.screen = screen
        self.bullet_rect = pygame.rect.Rect((0, 0, 5, 10))
        self.bullet_rect.midtop = ship.ship_rect.midtop
        self.bullet_speed = 3

    def update(self):
        self.bullet_rect.y -= self.bullet_speed

    def draw(self):
        pygame.draw.rect(self.screen, (0, 155, 0), self.bullet_rect)

class Alien():
    def __init__(self, screen):
        self.screen = screen
        self.alien_rect = pygame.rect.Rect((0, 0, 30, 30))
        self.alien_rect.x = 0
        self.alien_rect.y = 0
        alien_speed = 1

    def update(self):
        self.alien_rect.x += 1
        if self.alien_rect.x > WIDTH:
            self.alien_rect.x = 0

    def draw(self):
        pygame.draw.rect(self.screen, (255, 0, 0), self.alien_rect)

################################################################################

def check_events(screen, ship, bullets):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                ship.moving_right = True
            elif event.key == pygame.K_LEFT:
                ship.moving_left = True
            elif event.key == pygame.K_SPACE:
                new_bullet = Bullet(screen, ship)
                bullets.append(new_bullet)
            elif event.key == pygame.K_q:
                sys.exit()
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT:
                ship.moving_right = False
            elif event.key == pygame.K_LEFT:
                ship.moving_left = False

def update_bullets(bullets):
    for b in bullets:
        b.draw()
        b.update()
        if b.bullet_rect.bottom <= 0:
            bullets.remove(b)

def update_aliens(aliens):
    for a in aliens:
        a.draw()

def create_fleet(screen, aliens):
    alien = Alien(screen)
    av_space_x = WIDTH - (2 * alien.alien_rect.width)
    nb_aliens = av_space_x // (2 * alien.alien_rect.width)
    for an in range(nb_aliens):
        alien = Alien(screen)
        alien.alien_rect.x = alien.alien_rect.width + 2 * alien.alien_rect.width * an
        aliens.append(alien)

def run_game():
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Space Invader")

    bullets = []
    aliens = []
    ship = Ship(screen)
    alien = Alien(screen)
    create_fleet(screen, aliens)

    while True:
        check_events(screen, ship, bullets)
        screen.fill(BG_COLOR)
        ship.update()
        ship.draw()
        update_bullets(bullets)
        update_aliens(aliens)
        pygame.display.flip()


if __name__ == '__main__':
    run_game()
