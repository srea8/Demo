import pygame
from pygame.sprite import Sprite
from time import sleep

class Alien(Sprite):
    def __init__(self,ai_setting,screen):
        super(Alien,self).__init__()
        self.screen = screen
        self.ai_setting = ai_setting

        self.image = pygame.image.load('images/alien.bmp')
        self.rect = self.image.get_rect()

        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def biltme(self):
        self.screen.blit(self.image,self.rect)

    def create_fleet(self,ai_settings,screen,aliens,ship):
        alien = Alien(ai_settings,screen)
        alien_width = alien.rect.width
        alien_height = alien.rect.height
        ship_height = ship.rect.height
        available_space_x = ai_settings.screen_width - 2 * alien_width
        available_space_y = ai_settings.screen_height - (5 * alien_height) - ship_height
        number_aliens_x = int(available_space_x/(2*alien_width))
        number_aliens_y = int(available_space_y/(2*alien_height))

        for alien_number_y in range(number_aliens_y):
            for alien_number_x in range(number_aliens_x):
                alien = Alien(ai_settings,screen)
                alien.x = alien_width + 2 * alien_width * alien_number_x
                alien.y = alien_height + 2 * alien_height * alien_number_y
                alien.rect.x = alien.x
                alien.rect.y = alien.y
                aliens.add(alien)

    def update(self, *args):
        self.x = float(self.x)
        self.x += (self.ai_setting.alien_speed_factor*self.ai_setting.fleet_direction)
        self.rect.x = self.x

    def check_edges(self):
        screen_rect = self.screen.get_rect()
        if(self.rect.right >= screen_rect.right-10):
            return True
        elif self.rect.left <= 10:
            return True

    def change_fleet_direction(self, ai_settings, aliens):
        for alien in aliens.sprites():
            alien.rect.y += ai_settings.fleet_drop_speed
        ai_settings.fleet_direction *= -1

    def check_fleet_edges(self,ai_settings,aliens):
        for alien in aliens.sprites():
            if alien.check_edges():
                self.change_fleet_direction(ai_settings, aliens)
                break

    def update_aliens(self, ai_settings, aliens, ship, screen, stats, bullets):
        self.check_fleet_edges(ai_settings, aliens)
        aliens.update()

        if pygame.sprite.spritecollide(ship, aliens, True):
            self.ship_hit(ai_settings, stats, screen, ship, aliens, bullets)

        self.check_aliens_bottom(ai_settings,stats,screen,ship,aliens,bullets)

    def ship_hit(self,ai_settings,stats,screen,ship,aliens,bullets):
        stats.ships_left -= 1

        aliens.empty()
        bullets.empty()

        self.create_fleet(ai_settings, screen, aliens, ship)
        ship.center_ship()

        sleep(1)

        if stats.ships_left == 0:
            stats.game_active = False

    def check_aliens_bottom(self,ai_settings,stats,screen,ship,aliens,bullets):
        screen_rect = screen.get_rect()
        for alien in aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                self.ship_hit(ai_settings,stats,screen,ship,aliens,bullets)
                break
