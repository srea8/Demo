import pygame

class Ship():
    def __init__(self,screen):
        self.screen = screen

        self.image = pygame.image.load('images/ship.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom - 10

        self.move_right = False
        self.move_left = False
        self.move_up = False
        self.move_down = False
        self.centerx = float(self.rect.centerx)
        self.centery = float(self.rect.centery)

    def update(self,ship_speed_factor = 1):
        if self.move_right :
            if self.rect.centerx <= 1330:
                self.centerx += ship_speed_factor
        if self.move_left:
            if self.rect.centerx >= 30:
                self.centerx -= ship_speed_factor
        if self.move_up:
            if self.rect.centery >= 30:
                self.centery -= ship_speed_factor
        if self.move_down:
            if self.rect.centery <= 690:
                self.centery += ship_speed_factor
        self.rect.centerx = self.centerx
        self.rect.centery = self.centery

    def blitme(self):
        self.screen.blit(self.image,self.rect)

    def center_ship(self):
        self.centerx = self.screen_rect.centerx
        self.centery = self.screen_rect.bottom - 30