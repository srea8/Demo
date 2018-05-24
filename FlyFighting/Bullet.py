import pygame
import time

from pygame.sprite import Sprite
class Bullet(Sprite):

    def __init__(self,ai_setting,screen,ship):
        super().__init__()
        self.screen = screen

        self.rect = pygame.Rect(0, 0, ai_setting.bullet_width, ai_setting.bullet_height)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top

        self.y = float(self.rect.y)

        self.bullet_time = time.time()
        self.bullet_space = False
        self.color = ai_setting.bullet_color
        self.speed_factor = ai_setting.bullet_speed_factor

    def update(self):
        self.y -= self.speed_factor
        self.rect.y = self.y

    def fire_bullet(self,ai_setting,screen,ship,bullets):
        if self.bullet_space == True:
            if(time.time() - self.bullet_time > 0.1):
                if len(bullets) < ai_setting.bullet_allowed:
                    new_bullet = Bullet(ai_setting, screen, ship)
                    bullets.add(new_bullet)
                    self.bullet_time = time.time()

    def draw_bullet(self):
        pygame.draw.rect(self.screen,self.color,self.rect)

    def update_bullets(self,bullets,aliens):
        bullets.update()
        for bullet in bullets.sprites():
            bullet.draw_bullet()
        for bullet in bullets.copy():
            if bullet.rect.bottom <= 0:
                bullets.remove(bullet)
        collisions = pygame.sprite.groupcollide(bullets,aliens,True,True)

