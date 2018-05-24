import pygame.sysfont

class Button():
    def __init__(self,ai_settings,screen,msg):
        self.screen = screen
        self.screen_rect = screen.get_rect()

        self.width = 200
        self.height = 50
        self.button_color = (255, 0, 0)
        self.text_color = (255, 255, 255)
        self.font = pygame.font.SysFont('arial',30)

        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.center = self.screen_rect.center

        self.msg_image = self.font.render(msg, True, self.text_color, self.button_color)
        self.msg_image_rect = self.msg_image.get_rect()
        self.msg_image_rect.center = self.rect.center


    def draw_button(self):
        self.screen.fill(self.button_color,self.rect)
        self.screen.blit(self.msg_image,self.msg_image_rect)

    def check_paly_button(self,ai_setting,stats,play_button,mouse_x,mouse_y):
        botton_clicked = play_button.rect.collidepoint(mouse_x, mouse_y)
        if not stats.game_active and botton_clicked:
            stats.ships_left = ai_setting.ship_limit
            pygame.mouse.set_visible(False)
            stats.game_active = True